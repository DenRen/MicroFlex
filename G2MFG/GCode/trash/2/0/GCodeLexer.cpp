#include "GCodeLexer.hpp"

#include <fstream>

int GLexer::process_Gcmd () {
    cur_lexem = "G";
    cur_value = "G command";

    return 1;
}

int GLexer::process_Mcmd () {
    cur_lexem = "M";
    cur_value = "M command";

    return 1;
}

int GLexer::process_coord () {
    cur_lexem = yytext[0];
    cur_value = "Coord symbol";

    return 1;
}

int GLexer::process_number () {
    cur_lexem = yytext;
    cur_value = "number";
    
    return 1;
}

int GLexer::process_float_number () {
    cur_lexem = yytext;
    cur_value = "float number";
    
    return 1;
}

int GLexer::process_percent () {
    prog_started = !prog_started;

    if (prog_started)
        cur_lexem = "Program started";
    else
        cur_lexem = "Progrm finished";

    cur_value = "percet";
 
    return 1;
 }

int GLexer::procces_unexpected_cmd () {
    
    cur_lexem = yytext;
    cur_value = "Unknown command";

    return 1;
 }

void GLexer::print_current () {
    if (cur_lexem == "\n") {
        std::cout << std::endl;
        return;
    } else if (cur_lexem == "%") {
        if (prog_started)
            std::cout << "Programm started" << std::endl;
        else
            std::cout << "Programm finsihed" << std::endl;
        return;
    }
    
    std::cout << cur_lexem << " {" << cur_value << "}" << std::endl;
}