#include "MFGCode/MFGCode.hpp"
#include "UART/libuart.hpp"
#include <fstream>

const char name_file[] = "commands.gcode";

void write_mfgcode (const mf::mfgcmd& cmd, mf::uart& serial_port) {
    const uint8_t cmd_id = 'G';
    const int32_t value = cmd.value_;

    serial_port.write ((const char*) &cmd_id, 1);
    serial_port.write ((const char*) &cmd_id, sizeof (cmd_id));
}

int main () {
    try {
        // Open port
        mf::uart serial_port ("/dev/ttyUSB0");

        // Calculate MFGCode
        std::ifstream gcode_file (name_file);
        gcode::GLexer glexer (gcode_file);
        gcode::gprogram gprog = glexer.parse ();

        gprog.dump ();
        std::cout << std::endl;

        mf::kinematic kinematic (178, 65, 180, 81.6, 230, 76);

        mf::mfgprogram mfprog (gprog, kinematic);
        mfprog.dump ();


        int32_t val;
        // Send cmds
        for (auto frame = mfprog.begin (); frame != mfprog.end (); ++frame) {
            for (auto cmd = frame->begin (); cmd != frame->end (); ++cmd) {
                write_mfgcode (*cmd, serial_port);
                std::cout << "AA" << std::endl;
            }
            std::cout << "AA" << std::endl;
            sleep (3);
        }

    } catch (std::runtime_error& error) {
        std::cout << error.what ();
        return 0;
    } catch (std::invalid_argument& inv_err) {
        std::cout << inv_err.what ();
        return 0;
    }
}