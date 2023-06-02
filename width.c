#include "main.h"

/**
 * _width - the function
 * @a:string
 * @i: list
 * @list: list
 * Return:!= 0
 */
int _width(const char *a, int *i, va_list list)
{
	int d;
	int width = 0;

	for (d = *i + 1; a[d] != '\0'; d++)
	{
		if (is_digit(a[d]))
		{
			width *= 10;
			width += a[d] - '0';
		}
		else if (a[d] == '*')
		{
			d++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = d - 1;
	return (width);
}
