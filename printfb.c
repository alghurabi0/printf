#include "main.h"
#include <stdio.h>
#include <stdarg.h>
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
