#include "main.h"

/**
 * _hexa_upper - to prints a number in upper hexadecimal
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _hexa_upper(va_list t, char b[], int f, int width, int prec, int size)
{
	return (_hexa(t, "0123456789ABCDEF", b, f,
				'X', width, prec, size));
}
