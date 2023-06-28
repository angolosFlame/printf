#include "main.h"

/**
 * get_width - Calculates the width for printing
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cub_i;
	int width = 0;

	for (cub_i = *i + 1; format[cub_i] != '\0'; cub_i++)
	{
		if (is_digit(format[cub_i]))
		{
			width *= 10;
			width += format[cub_i] - '0';
		}
		else if (format[cub_i] == '*')
		{
			cub_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cub_i - 1;

	return (width);
}
