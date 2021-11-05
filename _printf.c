#include "main.h"

/**
 * _printf - prints a string according to a format
 * @format: format specifier
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, len = 0;
	int n;
	char *s;
	char *tmp;
	va_list arg;

	if (format == NULL || *format == '%')
	{
		exit(98);
	}
	va_start(arg, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			_putchar(format[i]);
			len++;
			i++;
		}
		if (format[i] == '\0')
			break;
		if (format[i] != '\0')
			i++;
		if (format[i] == ' ')
			i++;

		switch (format[i])
		{
			case 'c':
				n = va_arg(arg, int);
					if (n == '\0')
					{
						break;
					}
					else
					{
						_putchar(n);
					}
				len++;
				break;
			case 's':
				s = va_arg(arg, char *);
					if (s == NULL)
					{
						output("(null)");
						len += 6;
					}
					else
					{
						output(s);
						len += _strlen(s);
					}
				break;
			case 'd':
				n = va_arg(arg, int);
				tmp = malloc(sizeof(n));
					if (tmp == NULL)
					{
						return ('\0');
					}
					if (n == '\0')
					{
						_putchar('0');
						len++;
					}
					else
					{
						s = _itoa(n, tmp, 10);
						output(s);
						len += _strlen(s);
					}
				free(tmp);
				break;
			case 'i':
				n = va_arg(arg, int);
				tmp = malloc(sizeof(n));
					if (tmp == NULL)
					{
						return ('\0');
					}
					if (n == '\0')
					{
						_putchar('0');
						len++;
					}
					else
					{
						s = _itoa(n, tmp, 10);
						output(s);
						len += _strlen(s);
					}
				free(tmp);
				break;
			case 'o':
				n = va_arg(arg, unsigned int);
				tmp = malloc(sizeof(n));
					if (tmp == NULL)
					{
						return ('\0');
					}
					if (n == '\0')
					{
						_putchar('0');
						len++;
					}

					else
					{
						s = _itoa(n, tmp, 8);
						output(s);
						len += _strlen(s);
					}
				free(tmp);
				break;
			case 'X':
				n = va_arg(arg, unsigned int);
				tmp = malloc(sizeof(n));
					if (tmp == NULL)
					{
						return ('\0');
					}
					if (n == '\0')
					{
						_putchar('0');
						len++;
					}
					else
					{
						s = _itoa(n, tmp, 16);
						output(s);
						len += _strlen(s);
					}
				free(tmp);
				break;
			case '%':
				_putchar('%');
				len++;
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				len++;
				len++;
				break;
		}
	}
	va_end(arg);

	return (len);
}
