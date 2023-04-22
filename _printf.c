#include "main.h"
#include <stdio.h>
/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int i;
specifier_t specifiers[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{0, NULL}
};

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
for (i = 0; specifiers[i].spec; i++)
{
if (*format == specifiers[i].spec)
{
specifiers[i].func(args);
count++;
break;
}
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);

return (count);
}

