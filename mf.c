#include "main.h"

/**
 * _reverse - the function
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */

int _reverse(va_list t, char b[], int f,
		int width, int prec, int size)
{
	char *s;
	int i, j = 0;

	NDS(b);
	NDS(f);
	NDS(width);
	NDS(size);

	s = va_arg(t, char *);

	if (s == NULL)
	{
		NDS(prec);

		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char a = s[i];

		write(1, &a, 1);
		j++;
	}
	return (j);
}
