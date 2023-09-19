#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf custom function implementation
 * @format: format.
 *
 * Auth: Kennedy Gichuru
 *	Winnie Kiarago
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int loop_c;
	int printed = 0;
	int printed_chars = 0;
	/*buff_ind - index to keep track of position in buffer*/
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	for (loop_c = 0; format && format[loop_c] != '\0'; loop_c++)
	{
		if (format[loop_c] != '%')
		{
			buffer[buff_ind++] = format[loop_c];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}

			/* putchar like: write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &loop_c);
			width = get_width(format, &loop_c, args);
			precision = get_precision(format, &loop_c, args);
			size = get_size(format, &loop_c);
			++loop_c;
			printed = handle_print(format, &loop_c, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array
 * @buff_ind: index to keep track of position in buffer
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}
