#include "MFGCode/MFGCode.hpp"
#include <fstream>

const char name_file[] = "GCode/test_Gx.gcode";

int main () {
    std::ifstream gcode_file (name_file);
    gcode::GLexer glexer (gcode_file);
    gcode::gprogram gprog = glexer.parse ();

    gprog.dump ();
    std::cout << std::endl;

    mf::kinematic kinematic (178, 65, 180, 81.6, 230, 76);

    mf::mfgprogram mfprog (gprog, kinematic);
    mfprog.dump ();    
}