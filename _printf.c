#include "main.h"

void _buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, t = 0, c = 0;
	int f, width, prec, size, k = 0;
	va_list list;
	char b[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			b[k++] = format[i];
			if (k == BUFF_SIZE)
				_buffer(b, &k);
			c++;
		}
		else
		{
			_buffer(b, &k);
			f = _flags(format, &i);
			width = _width(format, &i, list);
			prec = _precision(format, &i, list);
			size = _size(format, &i);
			++i;
			t = handle_print(format, &i, list, b,
					f, width, prec, size);
			if (t == -1)
				return (-1);
			c += t;
		}
	}
	_buffer(b, &k);

	va_end(list);

	return (c);
}

/**
 * _buffer - the function
 * @b: Array
 * @k: parameter
 */
void _buffer(char b[], int *k)
{
	if (*k > 0)
		write(1, &b[0], *k);

	*k = 0;
}
