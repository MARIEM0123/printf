#include "main.h"

/**
 * is_printable - the function
 * @c: Char
 * Return: 1 or 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * ah_code - the function
 * @b: Array
 * @i: parameter
 * @ascii: parameter
 * Return: != 0
 */
int ah_code(char ascii, char b[], int i)
{
	char a[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	b[i++] = '\\';
	b[i++] = 'x';

	b[i++] = a[ascii / 16];
	b[i] = a[ascii % 16];
	return (5);
}

/**
 * is_digit - The function
 * @c: parameter
 * Return: 1 or 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * cvt_size_num - the function
 * @num: parameter
 * @size: size
 * Return: != 0
 */
long int cvt_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * cvt_size_unsigned - the function
 * @n: parameter
 * @size: size
 * Return: != 0
 */
long int cvt_size_unsigned(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((unsigned short)n);
	return ((unsigned int)n);
}
