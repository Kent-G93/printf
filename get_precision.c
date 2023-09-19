#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int curnt_i = *i + 1;
	int precision = -1;

	if (format[curnt_i] != '.')
		return (precision);

	precision = 0;

	for (curnt_i += 1; format[curnt_i] != '\0'; curnt_i++)
	{
		if (is_digit(format[curnt_i]))
		{
			precision *= 10;
			precision += format[curnt_i] - '0';
		}
		else if (format[curnt_i] == '*')
		{
			curnt_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curnt_i - 1;

	return (precision);
}
