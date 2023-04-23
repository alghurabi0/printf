#include "main.h"
#include <stdio.h>
#include <stdlib.h>
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
int i, count = 0;
char *str;

va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
count += print_string(str);
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
default:
count += print_char('%');
count += print_char(format[i]);
break;
}
}
else
count += print_char(format[i]);
}
va_end(args);
return (count);
}

