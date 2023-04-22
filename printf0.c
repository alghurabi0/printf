#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a single character
 * @args: the va_list containing the argument
 * @count: count
 * Return: the number of characters printed
 */
int print_char(va_list args, int count)
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
int print_string(va_list args, int count)
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
