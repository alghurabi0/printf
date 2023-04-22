#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#define BUF_SIZE 1024
/**
 * print_format_specifier - Prints a character or string
 * based on the conversion specifier
 * @args: The va_list containing the argument
 * @count: The current count of characters printed
 * @specifier: The conversion specifier
 * Return: The updated count of characters printed
 */
int print_format_specifier(va_list args, int count, char specifier)
{
	switch (specifier)
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
		case 'u':
			count = print_unsigned(args, count);
			break;
		case 'o':
			count = print_octal(args, count);
			break;
		case 'x':
			count = print_hex(args, count, 0);
			break;
		case 'X':
			count = print_hex(args, count, 1);
			break;
		case '%':
			putchar('%');
			count++;
			break;
		default:
			putchar('%');
			putchar(specifier);
			count += 2;
	}
	return (count);
}
/**
 * print_format_string - Prints a format string with arguments
 * @format: The format string containing zero or more directives
 * @args: The va_list containing the optional arguments referenced
 * by the format string
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings)
 */
int print_format_string(const char *format, va_list args)
{
	char buffer[BUF_SIZE];
	int buffer_index = 0;

	 while (*format)
	 {
		 if (*format == '%')
		 {
			 format++;
			 buffer_index = print_format_specifier(args, buffer_index, *format);
		 }
		 else
			 buffer[buffer_index++] = *format++;
		 if (buffer_index >= BUF_SIZE - 1)
		 {
			 write(STDOUT_FILENO, buffer, buffer_index);
			 buffer_index = 0;
		 }
	 }
	 if (buffer_index)
		 write(STDOUT_FILENO, buffer, buffer_index);
	 return buffer_index;
}
/**
 * _printf - Prints output according to a format
 * @format: The format string containing zero or more directives
 * @...: The optional arguments referenced by the format string
 * Return: The number of characters printed (excluding the null
 * byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);

	count = print_format_string(format, args);

	va_end(args);
	return (count);
}
