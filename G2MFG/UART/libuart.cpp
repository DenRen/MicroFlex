#include "libuart.hpp"

#include <unistd.h>
#include <fcntl.h>
#include "debug_func.hpp"
#include <cstring>
#include <stdexcept>

namespace mf {

int open_port (const char* name_port, int flags) {
    int serial_port = open (name_port, flags);
    if (serial_port < 0) {
        perror ("open");
        throw std::runtime_error ("Failed to open serial port");
    }

    return serial_port;
}

// serial_port - correct
static void configure_port (int serial_port, BAUDRATE baud_rate, int vmin, int vtime) {

    struct termios tty = {0};
    if (tcgetattr (serial_port, &tty) != 0) {
        perror ("tcgetattr");
        close (serial_port);
        throw std::runtime_error ("Failed to get attr from serial port");
    }
    
    //  Control mode flags
    tty.c_cflag |= PARENB;  // Parity
    tty.c_cflag |= CSTOPB;  // Num Stop Bits

    tty.c_cflag &= ~CSIZE;  // Cleer size 
    tty.c_cflag |= CS8;     // Set size in 8 bit

    tty.c_cflag &= ~CRTSCTS;

    tty.c_cflag |= CREAD | CLOCAL;

    // Local mode flags
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ECHOE;
    tty.c_lflag &= ~ECHONL;

    tty.c_lflag &= ~ISIG;

    // Input mode flags
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP |
                     INLCR  | IGNCR  | ICRNL);

    // Output mode flags
    tty.c_oflag &= ~OPOST;
    tty.c_oflag &= ~ONLCR;

    // VMIN and VTIME (c_cc)
    tty.c_cc[VMIN]  = vmin;
    tty.c_cc[VTIME] = vtime;

    // Baud Rate

    cfsetispeed (&tty, static_cast <int> (baud_rate));
    cfsetospeed (&tty, static_cast <int> (baud_rate));

    if (tcsetattr (serial_port, TCSANOW, &tty) != 0) {
        perror ("tcsetattr");
        close (serial_port);
        throw std::runtime_error ("Failed to get attr from serial port");
    }
}

uart::uart (const char* name_port, int flags, BAUDRATE baud_rate,
            int vmin, int vtime)
{
    int serial_port = open_port (name_port, flags);   
    configure_port (serial_port, baud_rate, vmin, vtime);
}

uart::~uart () {
    close (serial_port_);
}

}