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

	va_list arg;

	va_start(arg, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			putchar(format[i]);
			len++;
			i++;
        }
		if (format[i] == '\0')
	{
		break;
	}
		if (format[i] != '\0')
		{
		i++;
		}
		switch(format[i])
		{
			case 'c':
				n = va_arg(arg,int);
				putchar(n);
				len++;
				break;
			case 's':
				s = va_arg(arg,char *);
				puts(s);
				len += strlen(s);
				break;
			case '%':
				putchar(format[i]);
				len++;
				break;
			default:
				break;
		}
	}
	va_end(arg);

	return (len);
}
