// Tasks: G28, G1 with F arg
#include <iostream>
#include <fstream>
#include <string>
#include "GCodeDriver.hpp"

const char name_file[] = "test_Gx.gcode";

int main () {
    std::ifstream gcode_file (name_file);

    FlexLexer* lexer = new yyFlexLexer (gcode_file, std::cout);
    yy::GCodeDriver driver(lexer);
    
    driver.parse();
    driver.printout();
}