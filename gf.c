#include "main.h"

/**
 * _octal - Prints an unsigned number
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _octal(va_list t, char b[],
		int f, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(t, unsigned long int);
	unsigned long int init = n;

	NDS(width);

	n = cvt_size_unsigned(n, size);

	if (n == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		b[i--] = (n % 8) + '0';
		n /= 8;
	}
	if (f & F_HASH && init != 0)
		b[i--] = '0';
	i++;
	return (hw_unsgnd(0, i, b, f, width, prec, size));
}
