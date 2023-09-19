#include "main.h"


/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */


int get_width(const char *format, int *i, va_list list)
{
        int curnt_i;
        int width = 0;

        for (curnt_i = *i + 1; format[curnt_i] != '\0'; curnt_i++)
        {
                if (is_digit(format[curnt_i]))
                {
                        width *= 10;
                        width += format[curnt_i] - '0';
                }
                else if (format[curnt_i] == '*')
                {
                        curnt_i++;
                        width = va_arg(list, int);
                        break;
                }
                else
                        break;
        }
        *i = curnt_i - 1;
        return (width);
}
