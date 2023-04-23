#include "main.h"

/**
 * print_char - prints a character
 * @args: the va_list containing the character to print
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
return (_putchar(va_arg(args, int)));
}

/**
 * print_string - prints a string
 * @args: the va_list containing the string to print
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;

if (str == NULL)
str = "(null)";

while (*str)
{
count += _putchar(*str);
str++;
}

return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: the va_list (unused)
 *
 * Return: the number of characters printed
 */
int print_percent(__attribute__((unused)) va_list args)
{
return (_putchar('%'));
}
/**
 * print_integer - prints an integer
 * @args: the integer to print
 * Return: the number of characters printed
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		count += print_integer(args);
	count += _putchar((n % 10) + '0');
	return (count);
}
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
{"d", print_integer},
{"i", print_integer},
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
