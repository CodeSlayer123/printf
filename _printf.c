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

		switch (format[i])
		{
			case 'c':
				n = va_arg(arg, int);
					if (n == '\0')
					{
						_putchar(' ');
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
						output("(null)\n");
					}
					else
					{
						output(s);
					}
				len += strlen(s);
				break;
			case 'd':
				tmp = malloc(sizeof(va_arg(arg, int)));
					if (tmp == NULL)
					{
						return ('\0');
					}
				n = va_arg(arg, int);
					if (n == '\0')
					{
						_putchar('0');
					}
					else
					{
						s = _itoa(n, tmp, 10);
						output(s);
					}
				len += _strlen(s);
				free(tmp);
				break;
			case 'i':
				tmp = malloc(sizeof(va_arg(arg, int)));
					if (tmp == NULL)
					{
						return ('\0');
					}
				n = va_arg(arg, int);

					if (n == '\0')
					{
						_putchar('0');
					}
					else
					{
						s = _itoa(n, tmp, 10);
						output(s);
					}
				len += _strlen(s);
				free(tmp);
				break;
			case 'o':
				tmp = malloc(sizeof(va_arg(arg, unsigned int)));
					if (tmp == NULL)
					{
						return ('\0');
					}
				n = va_arg(arg, unsigned int);
					if (n == '\0')
					{
						_putchar('0');
					}

					else
					{
						s = _itoa(n, tmp, 8);
						output(s);
					}
				len += _strlen(s);
				free(tmp);
				break;
			case 'X':
				tmp = malloc(sizeof(va_arg(arg, unsigned int)));
					if (tmp == NULL)
					{
						return ('\0');
					}
				n = va_arg(arg, int);
					if (n == '\0')
					{
						_putchar('0');
					}
					else
					{
						s = _itoa(n, tmp, 16);
						output(s);
					}
				len += _strlen(s);
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
