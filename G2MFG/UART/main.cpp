#include <iostream>
#include "libuart.hpp"
#include "debug_func.hpp"
#include <string.h>

int main () {
    try {
        mf::uart serial_port ("/dev/ttyUSB1");

        const char msg[] = "1234asdfghfhgkhgkjfgd";
        serial_port.write (msg, sizeof (msg));

    } catch (std::runtime_error& error) {
        std::cout << error.what ();
        return 0;
    } catch (std::invalid_argument& inv_err) {
        std::cout << inv_err.what ();
        return 0;
    }
}