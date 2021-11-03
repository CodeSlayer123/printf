#include "main.h"
#include <unistd.h>

/**
 * _strlen - returns length of string
 * @s: string
 * Return: Always 0
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}

	return (i);
}

/**
 * _putchar - write a character to standard output
 * @c: character passed in
 * Return: byte size
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * output - print a string
 * @s: string array passed in
 * Return: void
 */
void output(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
}

/**
 * _strrev - reverse the numbers from _itoa
 * @str: string of numbers passed from _itoa
 * Return: the corrected string
 */
char *_strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}

/**
 * _itoa - convert integers to a string
 * @i: argument passed in
 * @strout: buffer passed in
 * @base: base of the number passed
 * Return: integers converted to a string
 */

char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	_strrev(strout);
	return (strout);
}
