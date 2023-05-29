#include "main.h"

void buffer_print(char buffer[], int *buff_ind);

/**
 * _printf - to print anything specified
 * @format: the format to print in.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
				buffer_print(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			buffer_print(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
		i++;
	}

	buffer_print(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * buffer_print - to prints the contents of the buffer if it exist
 * @buffer: an array of chars passed into the buffer
 * @buff_ind: Index at which to add next char, represents the length.
 */
void buffer_print(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

