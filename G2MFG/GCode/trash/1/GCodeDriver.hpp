#ifndef GCODEDRIVER_HPP
#define GCODEDRIVER_HPP


#include <vector>

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "GCodeGrammar.tab.hh"

enum class CMD_ID {
    G, M, X, Y, Z, F
};

class Igcode {
public:
    virtual CMD_ID GetId () const = 0;
    virtual ~Igcode () {}

    virtual void dump (std::ostream& out = std::cout) const = 0;
};

template <typename T>
class gcode : public Igcode {
    CMD_ID cmd_id_;
    T value_;

public:
    gcode (CMD_ID cmd_id, T value = 0) :
        cmd_id_ (cmd_id),
        value_ (value)
    {}

    CMD_ID GetId () const override {
        return cmd_id_;
    }

    void dump (std::ostream& out = std::cout) const {
        out << "id[" << static_cast <int> (cmd_id_) << "]: " << value_; 
    }
};

namespace yy {

template <typename T>
using lines_t = std::vector <std::vector <T>>;

class GCodeDriver {
    FlexLexer *lex_;
    lines_t <Igcode*> lines_;

public:
    GCodeDriver (FlexLexer* lex) :
        lex_ (lex)
    {}

    parser::token_type yylex (parser::semantic_type* yylval) {
        parser::token_type ttype = static_cast <parser::token_type> (lex_->yylex ());

        if (ttype == yy::parser::token_type::NUMBER)
            yylval->as <int> () = std::stoi (lex_->YYText ());
        
        return ttype;
    }

    bool parse () {
        parser parser (this);
        bool res = parser.parse ();
        return !res;
    }

    void insert (lines_t <Igcode*> lines) {
        lines_.assign (lines.begin (), lines.end ());
    }

    void printout () const {
        for (auto frames : lines_) {
            for (auto command : frames) {
                command->dump ();
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

};

}

#endif // GCODEDRIVER_HPP