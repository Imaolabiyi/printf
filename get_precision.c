#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: count of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision;

	if (format[curr_i] != '.')
		return (-1);

	precision = 0;
	curr_i += 1;
	while (format[curr_i] != '\0')
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;

		curr_i++;
	}
	*i = curr_i - 1;
	return (precision);
}
