#pragma once

#include <termios.h>
#include <fcntl.h>

namespace mf {

enum class BAUDRATE {
    BR_115200 = B115200
};

class uart {
    int serial_port_;

    void open_port (const char* name_port, int flags);
    void configure_port (BAUDRATE baud_rate, int vmin, int vtime);

public:
    uart (const char* name_port = "/dev/ttyUSB0", int flags = O_RDWR,
          BAUDRATE baud_rate = BAUDRATE::BR_115200,
          int vmin = 0, int vtime = 10);
    ~uart ();

    void write (const char* src, size_t size);
    void read  (      char* dst, size_t size);
};

}