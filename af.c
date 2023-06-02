#include "main.h"

/**
 * _char - Prints a char
 * @t: List
 * @b: array
 * @f: flags
 * @width: Width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _char(va_list t, char b[], int f, int width, int prec, int size)
{
	char c = va_arg(t, int);

	return (hw_char(c, b, f, width, prec, size));
}
