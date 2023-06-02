#include "main.h"
/**
 * _rot13 - the function
 * @t: List
 * @b: array
 * @f: flags
 * @width: width
 * @prec: Precision
 * @size: Size
 * Return: != 0
 */
int _rot13(va_list t, char b[], int f,
		int width, int prec, int size)
{
	char a;
	char *s;
	unsigned int i, j;
	int k = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(t, char *);
	NDS(b);
	NDS(f);
	NDS(width);
	NDS(prec);
	NDS(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == s[i])
			{
				a = output[j];
				write(1, &a, 1);
				k++;
				break;
			}
		}
		if (!input[j])
		{
			a = s[i];
			write(1, &a, 1);
			k++;
		}
	}
	return (k);
}
