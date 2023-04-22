#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/**
 * struct specifier - Structure for conversion specifiers and their functions
 * @spec: Conversion specifier
 * @func: Function to handle the specifier
 */
typedef struct specifier
{
char spec;
void (*func)(va_list);
} specifier_t;

int _printf(const char *format, ...);
void print_char(va_list args);
void print_string(va_list args);
void print_percent(va_list args);
void print_int(va_list args);

#endif
