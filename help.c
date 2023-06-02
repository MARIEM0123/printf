#include "main.h"

/**
 * hw_char - Prints a string
 * @c: parameter
 * @b: array
 * @f: flags.
 * @width: width.
 * @prec: precision
 * @size: Size
 * Return: != 0
 */
int hw_char(char c, char b[], int f,
		int width, int prec, int size)
{
	int i = 0;
	char d = ' ';

	NDS(prec);
	NDS(size);
	if (f & F_ZERO)
		d = '0';

	b[i++] = c;
	b[i] = '\0';

	if (width > 1)
	{
		b[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			b[BUFF_SIZE - i - 2] = d;
		if (f & F_MINUS)
			return (write(1, &b[0], 1) +
					write(1, &b[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &b[BUFF_SIZE - i - 1], width - 1) +
					write(1, &b[0], 1));
	}
	return (write(1, &b[0], 1));
}

/**
 * write_number - Function
 * @n: List
 * @k: parameter
 * @b: array
 * @f: flags
 * @width: width.
 * @prec: precision
 * @size: Size
 * Return: != 0
 */
int hw_number(int n, int k, char b[],
		int f, int width, int prec, int size)
{
	int l = BUFF_SIZE - k - 1;
	char d = ' ', c = 0;

	NDS(size);

	if ((f & F_ZERO) && !(f & F_MINUS))
		d = '0';
	if (n)
		c = '-';
	else if (f & F_PLUS)
		c = '+';
	else if (f & F_SPACE)
		c = ' ';

	return (hw_num(k, b, f, width, prec,
				l, d, c));
}

/**
 * write_num - the function
 * @k: parameter
 * @b: array
 * @f: Flags
 * @width: width
 * @prec: Precision
 * @l: length
 * @d: Parameter
 * @c: parameter
 * Return: != 0
 */
int hw_num(int k, char b[], int f, int width, int prec,
		int l, char d, char c)
{
	int i, init = 1;

	if (prec == 0 && k == BUFF_SIZE - 2 && b[k] == '0' && width == 0)
		return (0);
	if (prec == 0 && k == BUFF_SIZE - 2 && b[k] == '0')
		b[k] = d = ' ';
	if (prec > 0 && prec < l)
		d = ' ';
	while (prec > l)
		b[--k] = '0', l++;
	if (c != 0)
		l++;
	if (width > l)
	{
		for (i = 1; i < width - l + 1; i++)
			b[i] = d;
		b[i] = '\0';
		if (f & F_MINUS && d == ' ')
		{
			if (c)
				b[--k] = c;
			return (write(1, &b[k], l) + write(1, &b[1], i - 1));
		}
		else if (!(f & F_MINUS) && d == ' ')
		{
			if (c)
				b[--k] = c;
			return (write(1, &b[1], i - 1) + write(1, &b[k], l));
		}
		else if (!(f & F_MINUS) && d == '0')
		{
			if (c)
				b[--init] = c;
			return (write(1, &b[init], i - init) +
					write(1, &b[k], l - (1 - init)));
		}
	}
	if (c)
		b[--k] = c;
	return (write(1, &b[k], l));
}

/**
 * hw_unsgnd - function
 * @n: parameter
 * @k: parameter
 * @b: Array
 * @f: Flags
 * @width: Width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int hw_unsgnd(int n, int k, char b[], int f, int width, int prec, int size)
{
	int l = BUFF_SIZE - k - 1, i = 0;
	char d = ' ';

	NDS(n);
	NDS(size);

	if (prec == 0 && k == BUFF_SIZE - 2 && b[k] == '0')
		return (0);

	if (prec > 0 && prec < l)
		d = ' ';

	while (prec > l)
	{
		b[--k] = '0';
		l++;
	}
	if ((f & F_ZERO) && !(f & F_MINUS))
		d = '0';

	if (width > l)
	{
		for (i = 0; i < width - l; i++)
			b[i] = d;

		b[i] = '\0';
		if (f & F_MINUS)
		{
			return (write(1, &b[k], l) + write(1, &b[0], i));
		}
		else
		{
			return (write(1, &b[0], i) + write(1, &b[k], l));
		}
	}
	return (write(1, &b[k], l));
}

/**
 * hw_pointer - function
 * @b: Arrays
 * @k: parameter
 * @l: parameter
 * @width: width
 * @f: Flags
 * @d: parameter
 * @c: parameter
 * @init:parameter
 * Return: != 0
 */
int hw_pointer(char b[], int k, int l, int width, int f,
		char d, char c, int init)
{
	int i;

	if (width > l)
	{
		for (i = 3; i < width - l + 3; i++)
			b[i] = d;
		b[i] = '\0';
		if (f & F_MINUS && d == ' ')
		{
			b[--k] = 'x';
			b[--k] = '0';
			if (c)
				b[--k] = c;
			return (write(1, &b[k], l) + write(1, &b[3], i - 3));
		}
		else if (!(f & F_MINUS) && d == ' ')
		{b[--k] = 'x';
			b[--k] = '0';
			if (c)
				b[--k] = c;
			return (write(1, &b[3], i - 3) + write(1, &b[k], l));
		}
		else if (!(f & F_MINUS) && d == '0')
		{
			if (c)
				b[--init] = c;
			b[1] = '0';
			b[2] = 'x';
			return (write(1, &b[init], i - init) +
					write(1, &b[k], l - (1 - init) - 2));
		}
	}
	b[--k] = 'x';
	b[--k] = '0';
	if (c)
		b[--k] = c;
	return (write(1, &b[k], BUFF_SIZE - k - 1));
}
