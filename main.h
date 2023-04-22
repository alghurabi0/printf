#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
/**
 * struct format - struct for format types
 * @type: the type of format
 * @func: the function to print the format
 */
typedef struct format
{
char *type;
int (*func)(va_list);
} format_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */

