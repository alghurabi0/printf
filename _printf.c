#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
int j;
format_t formats[] = {
{"c", print_char},
{"s", print_string},
{"%", print_percent},
{NULL, NULL}
};

va_start(args, format);
while (format && format[i])
{
	if (format[i] == '%')
	{
		i++;
		j = 0;
		while (formats[j].type)
		{
			if (format[i] == *(formats[j].type))
			{
				count += formats[j].func(args);
				break;
			}
			j++;
		}
		if (!formats[j].type && format[i])
		{
			count += _putchar('%');
			count += _putchar(format[i]);
		}
	}
	else
		count += _putchar(format[i]);
	i++;
}
va_end(args);
return (count);
}
