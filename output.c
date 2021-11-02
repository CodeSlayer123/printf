#include <unistd.h>
#include "main.h"
/**
 * _putchar - print a character
 * @c: the character
 * Return: bytes
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * output - print stuff
 * @s: string passed in
 * Return: nada
 */

void output(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
}
