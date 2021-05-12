#include "libuart.hpp"

#include "debug_func.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <stdexcept>

namespace mf {

void uart::open_port (const char* name_port, int flags) {
    serial_port_ = open (name_port, flags);
    if (serial_port_ < 0) {
        perror ("open");
        throw std::runtime_error ("Failed to open serial port");
    }
}

// serial_port - correct
void uart::configure_port (BAUDRATE baud_rate, int vmin, int vtime) {

    struct termios tty = {0};
    if (tcgetattr (serial_port_, &tty) != 0) {
        perror ("tcgetattr");
        close (serial_port_);
        throw std::runtime_error ("Failed to get attr from serial port");
    }
    
    //  Control mode flags
    tty.c_cflag &= ~PARENB; // Parity
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

    //cfsetispeed (&tty, static_cast <int> (baud_rate));
    //cfsetospeed (&tty, static_cast <int> (baud_rate));

    cfsetispeed (&tty, B115200);
    cfsetospeed (&tty, B115200);

    if (tcsetattr (serial_port_, TCSANOW, &tty) != 0) {
        perror ("tcsetattr");
        close (serial_port_);
        throw std::runtime_error ("Failed to get attr from serial port");
    }
}

uart::uart (const char* name_port, int flags, BAUDRATE baud_rate,
            int vmin, int vtime)
{
    open_port (name_port, flags);   
    configure_port (baud_rate, vmin, vtime);
}

uart::~uart () {
    close (serial_port_);
}

void uart::write (const char* src, size_t size) {
    if (src == nullptr) {
        std::cerr << strerror (EINVAL) << std::endl;
        throw std::invalid_argument ("Source is nullptr!");
    }

    int len = 0;
    while (size) {
        len = ::write (serial_port_, src, size);
        if (len == -1) {
            perror ("write");
            throw std::runtime_error ("Error write");
        }
        else if (len == 0)
            throw std::runtime_error ("An attempt was made to write to a closed port\n");

        size -= len;
    }

}

void uart::read  (char* dst, size_t size) {
    if (dst == nullptr) {
        errno = EINVAL;
        throw std::invalid_argument ("Source is nullptr!");
    }

    int len = 0;
    while (size) {
        len = ::read (serial_port_, dst, size);
        if (len == -1) {
            perror ("read");
            throw std::runtime_error ("Error read");
        }
        else if (len == 0)
            throw std::runtime_error ("An attempt was made to read to a closed port\n");

        size -= len;
        dst += len;
    }
}

}