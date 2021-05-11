#ifndef GCODELEXER_H
#define GCODELEXER_H

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include <iostream>
#include <cstring>

class GLexer : public yyFlexLexer {
    std::string cur_lexem;
    std::string cur_value;

    bool prog_started = false;

    int process_Gcmd ();
    int process_Mcmd ();
    int process_coord ();
    int process_number ();
    int process_float_number ();
    int process_percent ();
    int procces_unexpected_cmd ();

public:

    GLexer (std::istream& input = std::cin, std::ostream& output = std::cout) :
        yyFlexLexer (input, output)
    {}

    int yylex () override;
    void print_current ();
};


#endif // GCODELEXER_H 