#include "main.h"
#include <stdarg.h>
/**
 * _printf - custom printf implementation
 * @format: The format string
 * This function emulates a simplified version of the printf function,
 * supporting the following format specifiers: 'c', 's', and '%'.
 *
 * Auth: Kennedy Gichuru
 *	Winnie Kiarago
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
		}
		if (*format == '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else if (*format == 'c')
		{
			char ch = va_arg(args, int);

			write(1, &ch, 1);
			printed_chars++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);
			int strlen = 0;

			while (str[strlen] != '\0')
				strlen++;
			write(1, str, strlen);
			printed_chars += strlen;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
