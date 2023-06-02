#include "main.h"

/**
 * _precision - the function
 * @format:String
 * @i: List
 * @list: list
 * Return: Precision
 */
int _precision(const char *format, int *i, va_list list)
{
	int k = *i + 1;
	int prec = -1;

	if (format[k] != '.')
		return (prec);

	prec = 0;
	for (k += 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			prec *= 10;
			prec += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = k - 1;
	return (prec);
}
