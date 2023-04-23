#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_integer(int n);
int print_unsigned_integer(unsigned int n);
int print_octal(unsigned int n);
int print_hexadecimal(unsigned int n, int uppercase);

#endif /* MAIN_H */

