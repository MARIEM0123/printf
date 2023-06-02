#include "main.h"

/**
 * _pointer - the function
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _pointer(va_list t, char b[], int f, int width, int prec, int size)
{
	char c = 0, d = ' ';
	int i = BUFF_SIZE - 2, l = 2, e = 1;
	unsigned long n;
	char a[] = "0123456789abcdef";
	void *m = va_arg(t, void *);

	NDS(width);
	NDS(size);

	if (m == NULL)
		return (write(1, "(nil)", 5));

	b[BUFF_SIZE - 1] = '\0';
	NDS(prec);

	n = (unsigned long)m;

	while (n > 0)
	{
		b[i--] = a[n % 16];
		n /= 16;
		l++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		d = '0';
	if (f & F_PLUS)
		c = '+', l++;
	else if (f & F_SPACE)
		c = ' ', l++;

	i++;
	return (hw_pointer(b, i, l, width, f, d, c, e));
}
