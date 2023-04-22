#include <stdio.h>
#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list containing the character to print
 */
void print_char(va_list args)
{
char c = va_arg(args, int);

putchar(c);
}

/**
 * print_string - Prints a string
 * @args: va_list containing the string to print
 */
void print_string(va_list args)
{
char *str = va_arg(args, char *);

while (*str)
{
putchar(*str);
str++;
}
}

/**
 * print_percent - Prints a percent sign
 * @args: va_list (unused)
 */
void print_percent(va_list args)
{
(void)args;
putchar('%');
}
/**
 * print_int - Prints an integer
 * @args: va_list
 */
void print_int(va_list args)
{
	int n = va_arg(args, int);
	char buffer[12];
	int i = 0;

	if (n == 0)
	{
		putchar('0');
		return;
	}
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		putchar(buffer[--i]);
}
