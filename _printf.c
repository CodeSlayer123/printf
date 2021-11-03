#include "main.h"
 /**
 * _printf - prints a string according to a format
 * @format: format specifier
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, n, len = 0;
	char *s, *tmp;
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
		{
			break;
		}
		else
		{
			i++;
		}
		switch (format[i])
		{
			case 'c':
				n = va_arg(arg, int);
				(n == '\0') ? (_putchar(' '), len++) : (putchar(n), len++);
				break;
			case 's':
				s = va_arg(arg, char *);
				(s == NULL) ? (output("(null)\n"), len += 6) :
					(output(s), len += _strlen(s));
				break;
			case 'd':
			case 'i':
				tmp = malloc(sizeof(va_arg(arg, int)));
				if (tmp == NULL)
					return ('\0');
				n = va_arg(arg, int);
				(n == '\0') ? (_putchar('0'), len++) :
					(s = _itoa(n, tmp, 10), output(s), len += _strlen(s));
				free(tmp);
				break;
			case 'o':
				tmp = malloc(sizeof(va_arg(arg, unsigned int)));
				if (tmp == NULL)
					return ('\0');
				n = va_arg(arg, unsigned int);
				(n == '\0') ? (_putchar('0'), len ++) :
					(s = _itoa(n, tmp, 8), output(s), len += _strlen(s));
				free(tmp);
				break;
			case 'X':
				tmp = malloc(sizeof(va_arg(arg, unsigned int)));
				if (tmp == NULL)
					return ('\0');
				n = va_arg(arg, int);
				(n == '\0') ? (_putchar('\0')) :
					(s = _itoa(n, tmp, 16), output(s), len += _strlen(s));
				free(tmp);
				break;
			case '%':
				_putchar('%');
				len++;
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				len += 2;
				break;
		}
	}
	va_end(arg);
	return (len);
}
