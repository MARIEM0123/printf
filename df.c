#include "main.h"

/**
 * _int - Print int
 * @t: List
 * @b: array
 * @f: flags
 * @width: width.
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _int(va_list t, char b[], int f, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int ng = 0;
	long int m = va_arg(t, long int);
	unsigned long int n;

	m = cvt_size_num(m, size);
	if (m == 0)
		b[i--] = '0';
	b[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)m;
	if (m < 0)
	{
		n = (unsigned long int)((-1) * m);
		ng = 1;
	}
	while (n > 0)
	{
		b[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (hw_number(ng, i, b, f, width, prec, size));
}
