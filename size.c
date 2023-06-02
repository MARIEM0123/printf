#include "main.h"

/**
 * _size - the function
 * @format: String
 * @i: List
 * Return: != 0
 */
int _size(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
		size = S_LONG;
	else if (format[k] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = k - 1;
	else
		*i = k;
	return (size);
}
