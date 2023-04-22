#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_unsigned - Prints an unsigned decimal integer argument
 * @args: The va_list containing the unsigned decimal integer argument
 * @count: The current count of characters printed
 * Return: The updated count of characters printed
 */
int print_unsigned(va_list args, int count)
{
	unsigned int arg = va_arg(args, unsigned int);
	unsigned int div = 1;

	while (arg / div > 9)
		div *= 10;
	do {
		unsigned int digit = arg / div;

		putchar('0' + digit);
		count++;
		arg -= digit * div;
		div /= 10;
		} while (div);
	return (count);
}
/**
 * print_octal - Prints an unsigned integer argument in octal
 * @args: The va_list containing the unsigned integer argument
 * @count: The current count of characters printed
 * Return: The updated count of characters printed
 */
int print_octal(va_list args, int count)
{
	unsigned int arg = va_arg(args, unsigned int);
	unsigned int mask = 1 << ((sizeof(unsigned int) * 8) - 3);
	int started = 0;

	while (mask)
	{
		int digit = (arg & mask) >> ((sizeof(unsigned int) * 8) - 3);

		if (digit || started || mask == 1)
		{
			putchar('0' + digit);
			count++;
			started = 1;
		}
		mask >>= 3;
	}
	return (count);
}
/**
 * print_hex - Prints an unsigned integer argument in hexadecimal
 * @args: The va_list containing the unsigned integer argument
 * @count: The current count of characters printed
 * @uppercase: Whether to use uppercase
 * Return: The updated count of characters printed
 */
int print_hex(va_list args, int count, int uppercase)
{
	unsigned int arg = va_arg(args, unsigned int);
	unsigned int mask;
	char hex[16] = "0123456789abcdef";
	int started;

	if (uppercase)
	{
		hex[10] = 'A';
		hex[11] = 'B';
		hex[12] = 'C';
		hex[13] = 'D';
		hex[14] = 'E';
		hex[15] = 'F';
	}
	started = 0;

	mask = 0xF0000000;
	while (mask)
	{
		int digit = (arg & mask) >> 28;

		if (digit || started || mask == 0xF)
		{
			putchar(hex[digit]);
			count++;
			started = 1;
		}
		mask >>= 4;
	}
	return (count);
}
