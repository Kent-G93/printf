#include "main.h"
#include <stdarg.h>

/**
 * _printf - custom printf implementation
 * @format: The format string
 *
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
        if (*format == '%')
        {
            format++; // Move past '%'
            switch (*format)
            {
                case 'c':
                    printed_chars += write(1, &va_arg(args, int), 1);
                    break;
                case 's':
                {
                    char *str = va_arg(args, char *);
                    while (*str)
                    {
                        printed_chars += write(1, str, 1);
                        str++;
                    }
                    break;
                }
                case '%':
                    printed_chars += write(1, "%", 1);
                    break;
                default:
                    printed_chars += write(1, &format[-1], 1);
                    printed_chars += write(1, format, 1);
                    break;
            }
        }
        else
        {
            printed_chars += write(1, format, 1);
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}
