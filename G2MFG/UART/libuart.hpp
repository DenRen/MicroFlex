#pragma once

#include <termios.h>

namespace mf {

enum class BAUDRATE {
    BR_115200 = B115200
};

class uart {
    int serial_port_;

public:
    uart (const char* name_port, int flags, BAUDRATE baud_rate = BAUDRATE::BR_115200,
            int vmin = 0, int vtime = 10);
    ~uart ();

    void write (const char* src, size_t size);
    void read  (const char* dst, size_t size);
};
}