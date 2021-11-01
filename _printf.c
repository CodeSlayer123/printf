#include "main.h"
 /**
 * _printf - prints a string according to a format
 * @format: format specifier
 * Return: number of characters printed
*/

 int _printf(const char *format, ...)
 {
     int i;
     /*int retlen;*/
     va_list arg;
     int len;
     len = strlen(format);
     /*retlen = 0;*/
     va_start(arg, format);

     for (i = 0; format[i] != '\0'; i++)
     {
         while (format[i] != '%')
         {
             putchar(format[i]);
            i++;

        }
         i++;


             switch(format[i])
         {
             case 'c':
                 putchar(va_arg(arg,int));
                 break;
             case 's':
                 puts(va_arg(arg,char *));
                 break;
         }


     }
     va_end(arg);
     return (len);
}
