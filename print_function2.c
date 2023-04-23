#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_hexadecimal - prints a hexadecimal number
 * @n: hexadecimal number to print
 * @uppercase: flag to indicate whether to print uppercase letters
 *
 * Return: number of characters printed
 */
int print_hexadecimal(unsigned int n, int uppercase)
{
int count = 0;
char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

if (n / 16)
{
count += print_hexadecimal(n / 16, uppercase);
}

count += print_char(hex[n % 16]);

return (count);
}
/**
 * print_binary - prints a binary number
 * @n: binary number to print
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n / 2);
	count += print_char((n % 2) + '0');
	return (count);
}
/**
 * print_string_non_printable - prints a string, replacing
 * non-printable characters with their ASCII code value in hexadecimal
 * @str: string to print
 * Return: number of characters printed
 */
int print_string_non_printable(char *str)
{
	int count = 0;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			count += print_char('\\');
			count += print_char('x');
			count += print_hexadecimal(*str, 1);
		}
		else
			count += print_char(*str);
		str++;
	}
	return (count);
}
