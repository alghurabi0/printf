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

