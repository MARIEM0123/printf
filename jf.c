#include "main.h"
/**
 * _hexa - to print a hexadecimal number
 * @t: List
 * @a: Array
 * @b: array
 * @f: flags
 * @gl: Calculates active flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _hexa(va_list t, char a[], char b[],
		int f, char gl, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);
	unsigned long int init = num;

	NDS(width);

	num = cvt_size_unsigned(num, size);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = a[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init != 0)
	{
		b[i--] = gl;
		b[i--] = '0';
	}
	i++;
	return (hw_unsgnd(0, i, b, f, width, prec, size));
}
