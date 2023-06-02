#include "main.h"

/**
 * handle_print - the function
 * @fmt: format
 * @l: List
 * @k: parameter
 * @b: array
 * @f: flags
 * @width: width.
 * @prec: Precision
 * @size: Size
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *k, va_list l, char b[],
	int f, int width, int prec, int size)
{
	int i, ln = 0, c = -1;
	fmt_t fmt_types[] = {
		{'c', _char}, {'s', _string}, {'%', _percent},
		{'i', _int}, {'d', _int}, {'b', _binary},
		{'u', _unsigned}, {'o', _octal}, {'x', _hexadecimal},
		{'X', _hexa_upper}, {'p', _pointer}, {'S', _non_printable},
		{'r', _reverse}, {'R', _rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*k] == fmt_types[i].fmt)
			return (fmt_types[i].fn(l, b, f, width, prec, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*k] == '\0')
			return (-1);
		ln += write(1, "%%", 1);
		if (fmt[*k - 1] == ' ')
			ln += write(1, " ", 1);
		else if (width)
		{
			--(*k);
			while (fmt[*k] != ' ' && fmt[*k] != '%')
				--(*k);
			if (fmt[*k] == ' ')
				--(*k);
			return (1);
		}
		ln += write(1, &fmt[*k], 1);
		return (ln);
	}
	return (c);
}
