#ifndef GCODEDRIVER_HPP
#define GCODEDRIVER_HPP

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "GCodeGrammar.tab.hh"
#include <vector>

enum class GCMD_ID {
    G, M, X, Y, Z, F
};

class Igcode {
public:
    GCMD_ID GetId () const;
    virtual ~Igcode ();

    virtual void dump (std::ostream& out = std::cout) const;
};

template <typename T>
class gcode : public Igcode {
    GCMD_ID cmd_id_;
    T value_;

public:
    gcode (GCMD_ID cmd_id, T value = 0) :
        cmd_id_ (cmd_id),
        value_ (value)
    {}

    GCMD_ID GetId () const override {
        return cmd_id_;
    }

    void dump (std::ostream& out = std::cout) const {
        out << "id[" << static_cast <int> (cmd_id_) << "]: " << value_; 
    }
};

namespace yy {

template <typename T>
using vectvect = std::vector <std::vector <T>>;

class GCodeDriver {
    FlexLexer *lex_;
    vectvect <Igcode*> lines_;

public:
    GCodeDriver (FlexLexer* lex) :
        lex_ (lex)
    {}

    parser::token_type yylex (parser::semantic_type* yylval) {
        parser::token_type ttype = static_cast <parser::token_type> (lex_->yylex ());
        if (ttype == yy::parser::token_type::NUMBER)
            yylval->as <int> () = std::stoi (lex_->YYText ());
        else if (ttype == yy::parser::token_type::FLOAT_NUMBER)
            yylval->as <float> () = std::stof (lex_->YYText ());
        
        return ttype;
    }

    bool parse () {
        parser parser (this);
        bool res = parser.parse ();
        return !res;
    }

    void insert (vectvect <Igcode*> lines) {
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