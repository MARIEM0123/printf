#include "main.h"
/**
 * _string - to prints a string
 * @t: List
 * @b: array
 * @f: flags
 * @width: width.
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _string(va_list t, char b[], int f, int width, int prec, int size)
{
	int l = 0, i;
	char *s = va_arg(t, char *);

	NDS(b);
	NDS(f);
	NDS(width);
	NDS(prec);
	NDS(size);
	if (s == NULL)
	{
		s = "(null)";
		if (prec >= 5)
			s = "     ";
	}
	while (s[l] != '\0')
		l++;

	if (prec >= 0 && prec < l)
		l = prec;

	if (width > l)
	{
		if (f & F_MINUS)
		{
			write(1, &s[0], l);
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], l);
			return (width);
		}
	}
	return (write(1, s, l));
}
