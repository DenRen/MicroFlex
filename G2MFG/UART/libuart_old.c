#include "libuart_old.h"

#include "debug_func.hpp"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <string.h>

void init_tty (struct termios* tty) {
    //  Control mode flags
    tty->c_cflag |= PARENB;  // Parity
    tty->c_cflag |= CSTOPB;  // Num Stop Bits

    tty->c_cflag &= ~CSIZE;  // Cleer size 
    tty->c_cflag |= CS8;     // Set size in 8 bit

    tty->c_cflag &= ~CRTSCTS;

    tty->c_cflag |= CREAD | CLOCAL;

    // Local mode flags
    tty->c_lflag &= ~ICANON;
    tty->c_lflag &= ~ECHO;
    tty->c_lflag &= ~ECHOE;
    tty->c_lflag &= ~ECHONL;

    tty->c_lflag &= ~ISIG;

    // Input mode flags
    tty->c_iflag &= ~(IXON | IXOFF | IXANY);
    tty->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP |
                     INLCR  | IGNCR  | ICRNL);

    // Output mode flags
    tty->c_oflag &= ~OPOST;
    tty->c_oflag &= ~ONLCR;

    // VMIN and VTIME (c_cc)
    tty->c_cc[VTIME] = 10;
    tty->c_cc[VMIN] = 0;

    // Baud Rate

    cfsetispeed (tty, B115200);
    cfsetospeed (tty, B115200);
}

int open_usb () {
    const char* name_port = "/dev/ttyUSB0";

    int serial_port = open (name_port, O_RDWR);
    if (serial_port < 0) {
        printf ("Error %i from open: %s\n", errno, strerror (errno));
        return -1;
    }

    struct termios tty = {0};
    if (tcgetattr (serial_port, &tty) != 0) {
        printf ("Error %i from tcgetattr: %s\n", errno, strerror (errno));
        close (serial_port);
        return -1;
    }

    init_tty (&tty);
    
    if (tcsetattr (serial_port, TCSANOW, &tty) != 0) {
        printf ("Error %i from tcgetattr: %s\n", errno, strerror (errno));
        close (serial_port);
        return -1;
    }

    return serial_port;
}

int Write (int fd, const char* src, unsigned size) {
    if (src == NULL) {
        errno = EINVAL;
        return -1;
    }

    int len = 0;
    while (size) {
        len = write (fd, src, size);
        if (len == -1)
            return -1;
        else if (len == 0) {
            errno = ENXIO;
            printf ("An attempt was made to write to a closed port\n");
            return -1;
        }

        size -= len;
    }

    return 0;
}

int Read (int fd, char* src, unsigned size) {
    if (src == NULL) {
        errno = EINVAL;
        return -1;
    }

    int len = 0;
    while (size) {
        len = read (fd, src, size);
        if (len == -1)
            return -1;
        else if (len == 0) {
            errno = ENXIO;
            printf ("An attempt was made to write to a closed port\n");
            return -1;
        }

        size -= len;
        src += len;
    }

    return 0;
}

int first_test () {

    const char msg[] = "The USB lib work!";

    int serial_port = open_usb ();

    CHECK_ERR (Write (serial_port, msg, sizeof (msg)), close (serial_port));

    close (serial_port);

    return 0;
}

int second_test () {

    const char msg[] = "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!"
                       "The USB lib work!""The USB lib work!""The USB lib work!""The USB lib work!";
    char buf[sizeof (msg)] = "";

    int serial_port = open_usb ();
    CHECK_ERR (serial_port, );

    CHECK_ERR (Write (serial_port, msg, sizeof (msg)), close (serial_port));

    CHECK_ERR (Read (serial_port, buf, sizeof (msg)), close (serial_port));

    printf ("%s\n", buf);

    if (strcmp (msg, buf) == 0)
        printf ("Strings is equal! Good!\n");

    close (serial_port);

    return 0;
}
