#include "main.h"

/**
 * _unsigned - Prints an unsigned number
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _unsigned(va_list t, char b[],
		int f, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);

	num = cvt_size_unsigned(num, size);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (hw_unsgnd(0, i, b, f, width, prec, size));
}
