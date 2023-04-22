#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int print_char(va_list args, int count);
int print_string(va_list args, int count);
int print_decimal(va_list args, int count);
int print_binary(va_list args, int count);
int print_unsigned(va_list args, int count);
int print_octal(va_list args, int count);
int print_hex(va_list args, int count, int uppercase);
int print_format_specifier(va_list args, int count, char specifier);
int print_format_string(const char *format, va_list args);
int _printf(const char *format, ...);

#endif /* CUSTOM_PRINTF_H */

