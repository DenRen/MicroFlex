// Tasks: G28, G1 with F arg
#include <iostream>
#include <fstream>
#include <string>

#include "GCodeLexer.hpp"

const char name_file[] = "test_full.gcode";

int main () {
    std::ifstream gcode_file (name_file);

    gcode::GLexer lexer (gcode_file);

    gcode::gprogram gprog = lexer.parse ();

    gprog.dump ();
}