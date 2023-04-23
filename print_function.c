#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * print_char - prints a character
 * @c: character to print
 *
 * Return: 1
 */
int print_char(char c)
{
return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
print_char(str[i]);
}

return (i);
}

/**
 * print_integer - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_integer(int n)
{
unsigned int num;
int count = 0;

if (n < 0)
{
count += print_char('-');
num = -n;
}
else
{
num = n;
}

if (num / 10)
{
count += print_integer(num / 10);
}

count += print_char((num % 10) + '0');

return (count);
}

/**
 * print_unsigned_integer - prints an unsigned integer
 * @n: unsigned integer to print
 *
 * Return: number of characters printed
 */
int print_unsigned_integer(unsigned int n)
{
int count = 0;

if (n / 10)
{
count += print_unsigned_integer(n / 10);
}

count += print_char((n % 10) + '0');

return (count);
}

/**
 * print_octal - prints an octal number
 * @n: octal number to print
 *
 * Return: number of characters printed
 */
int print_octal(unsigned int n)
{
int count = 0;

if (n / 8)
{
count += print_octal(n / 8);
}

count += print_char((n % 8) + '0');

return (count);
}
