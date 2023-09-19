#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curnt_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curnt_i = *i + 1; format[curnt_i] != '\0'; curnt_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curnt_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curnt_i - 1;

	return (flags);
}
