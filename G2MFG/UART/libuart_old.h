#pragma once

#include <termios.h>

int Write (int fd, const char* src, unsigned size);
int Read (int fd, char* src, unsigned size);

int open_usb ();

int first_test () ;
int second_test ();
