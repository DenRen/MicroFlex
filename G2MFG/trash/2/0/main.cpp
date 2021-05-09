// Tasks: G28, G1 with F arg
#include <iostream>
#include <fstream>
#include <string>
#include "GCodeLexer.hpp"

const char name_file[] = "test_Gx.gcode";

int main () {
    std::ifstream gcode_file (name_file);

    GLexer lexer (gcode_file);

    while (lexer.yylex ()) {
        lexer.print_current ();
    }
}