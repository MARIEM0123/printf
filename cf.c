#include "main.h"

/**
 * _percent - prints a percentage
 * @t: List
 * @b: array
 * @f: flags
 * @width: width.
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _percent(va_list t, char b[], int f, int width, int prec, int size)
{
	NDS(t);
	NDS(b);
	NDS(f);
	NDS(width);
	NDS(prec);
	NDS(size);
	return (write(1, "%%", 1));
}
