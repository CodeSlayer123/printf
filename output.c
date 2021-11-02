#include "main.h"
/**
 * output - print stuff
 * @s: string passed in
 */

void output(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
}
