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

