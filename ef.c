#include "main.h"

/**
 * _binary - Prints an unsigned number
 * @t: List
 * @b: array
 * @f: flags
 * @width: width.
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _binary(va_list t, char b[], int f, int width, int prec, int size)
{
	unsigned int n, m, i, s;
	unsigned int a[32];
	int num;

	NDS(b);
	NDS(f);
	NDS(width);
	NDS(prec);
	NDS(size);

	n = va_arg(t, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, s = 0, num = 0; i < 32; i++)
	{
		s += a[i];
		if (s || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			num++;
		}
	}
	return (num);
}
