#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a single character
 * @args: the va_list containing the argument
 * @count: count
 * Return: the number of characters printed
 */
static int print_char(va_list args, int count)
{
	char arg = va_arg(args, int);

	putchar(arg);
	return (count + 1);
}

/**
 * print_string - prints a string
 * @args: the va_list containing the argument
 * @count: count of printed
 * Return: the number of characters printed
 */
static int print_string(va_list args, int count)
{
	const char *arg = va_arg(args, const char *);

	while (*arg)
	{
		putchar(*arg++);
		count++;
	}

	return (count);
}
/**
 * print_decimal - Prints a decimal integer argument
 * @args: The va_list containing the decimal integer argument
 * @count: The current count of characters printed
 * Return: The updated count of characters printed
 */
int print_decimal(va_list args, int count)
{
	int arg = va_arg(args, int);
	int div = 1;

	if (arg < 0)
	{
		putchar('-');
		count++;
		arg = -arg;
	}
	while (arg / div > 9)
		div *= 10;
	do {

		int digit = arg / div;

		putchar('0' + digit);
		count++;
		arg -= digit * div;
		div /= 10;
	} while (div);
	return (count);
}
/**
 * print_binary - Prints an unsigned integer argument in binary
 * @args: The va_list containing the unsigned integer argument
 * @count: The current count of characters printed
 * Return: The updated count of characters printed
 */
int print_binary(va_list args, int count)
{
	unsigned int arg = va_arg(args, unsigned int);
	unsigned int mask = 1 << ((sizeof(unsigned int) * 8) - 1);

	while (mask)
	{
		putchar(arg & mask ? '1' : '0');
		count++;
		mask >>= 1;
	}
	return (count);
}
/**
 * _printf - prints formatted output to stdout
 * @format: a character string containing zero or more directives
 * @...: parameter
 * Return: the number of characters printed (excluding the null byte used to
 *         end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;

	va_start(args, format);
	while ((c = *format++))
	{
		if (c == '%')
		{
			switch (*format++)
			{
				case 'c':
					count = print_char(args, count);
					break;
				case 's':
					count = print_string(args, count);
					break;
				case 'd':
				case 'i':
					count = print_decimal(args, count);
					break;
				case 'b':
					count = print_binary(args, count);
					break;
				case '%':
					putchar('%');
					count++;
					break;
			}
		}
		else
		{
			putchar(c);
			count++;
		}
	}
	va_end(args);
	return (count);
}
