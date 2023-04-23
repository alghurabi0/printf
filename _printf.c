#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_format - prints a format specifier
 * @format: format specifier to print
 * @args: arguments to print
 *
 * Return: number of characters printed
 */
int print_format(const char *format, va_list args)
{
int count = 0;

switch (*format)
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
count += print_string(va_arg(args, char *));
break;
case '%':
count += print_char('%');
break;
case 'd':
case 'i':
count += print_integer(va_arg(args, int));
break;
case 'u':
count += print_unsigned_integer(va_arg(args, unsigned int));
break;
case 'o':
count += print_octal(va_arg(args, unsigned int));
break;
case 'x':
count += print_hexadecimal(va_arg(args, unsigned int), 0);
break;
case 'X':
count += print_hexadecimal(va_arg(args, unsigned int), 1);
break;
case 'p':
count += print_char('0');
count += print_char('x');
count += print_hexadecimal(va_arg(args, unsigned long), 1);
break;
case 'b':
count += print_binary(va_arg(args, unsigned int));
break;
default:
count += print_char('%');
count += print_char(*format);
break;
}
return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed (excluding the null byte used to end
 * output to strings)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
count += print_format(format, args);
format++;
}
else
{
count += print_char(*format);
format++;
}
}

va_end(args);

return (count);
}

