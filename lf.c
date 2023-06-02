#include "main.h"
int append_hexa(char, char[], int);
/**
 * _non_printable - the function
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */

int _non_printable(va_list t, char b[],
		int f, int width, int prec, int size)
{
	int i = 0, a = 0;
	char *s = va_arg(t, char *);

	NDS(f);
	NDS(width);
	NDS(prec);
	NDS(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[i] != '\0')
	{
		if (is_printable(s[i]))
			b[i + a] = s[i];
		else
			a += ah_code(s[i], b, i + a);

		i++;
	}
	b[i + a] = '\0';

	return (write(1, b, i + a));
}
