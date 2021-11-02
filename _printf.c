#include "main.h"

 /**
 * _printf - prints a string according to a format
 * @format: format specifier
 * Return: number of characters printed
*/
void my_itoa(int value, std::string& buf, int base);
int _printf(const char *format, ...)
 {
	int i, len = 0;
	unsigned int n;
	char *s;
	va_list arg;
	char str[30];

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
				n = va_arg(arg, double);
				if (i < 0)
				{
					n = -n;
					_putchar('-');
				}
				itoa (n, str, 10);
				output(str);
			   break;
			case 'i':
				n = va_arg(arg, double);
				if (i < 0)
				{
					n = -n;
					_putchar('-');
				}
				itoa (n, str, 10);
				output(str);
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
