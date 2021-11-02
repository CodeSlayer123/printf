#include "main.h"

 /**
 * _printf - prints a string according to a format
 * @format: format specifier
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
 {
	int i, len = 0;
	unsigned int n;
	char *s;
	char tmp[20];
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

		switch(format[i])
		{
			case 'c':
				n = va_arg(arg,int);
				_putchar(n);
				len++;
				break;
			case 's':
				s = va_arg(arg,char *);
				output(s);
				len += strlen(s);
				break;
			case 'd':
				s = _itoa(va_arg(arg, int), tmp, 10);
				output(s);
				break;
			case 'i':
				s = _itoa(va_arg(arg, int), tmp, 10);
				output(s);
			   break;
			case '%':
				_putchar('%');
				len++;
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				break;
		}
	}
	va_end(arg);

	return (len);
}
