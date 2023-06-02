#include "main.h"
/**
 * _hexadecimal - Prints a number in hexadecimal
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _hexadecimal(va_list t, char b[],
		int f, int width, int prec, int size)
{
	return (_hexa(t, "0123456789abcdef", b, f, 'x', width, prec, size));
}
