#include "main.h"
/**
 * _printf - prints a string according to a format
 * @format: format specifier
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int len, i, retlen;

	len = strlen(format);
	retlen = 0;
	i = 0;

	while (i < len)
	{
		putchar(format[i]);
		i++;
		retlen++;
	}



	return (retlen);
}
