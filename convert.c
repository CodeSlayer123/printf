#include "main.h"
/**
 * convert - convert number to proper format
 * @num: number given
 * Return: the number
 */

char *convert(unsigned int num, int base)
{
	static char Rep[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	while (num != 0)
	{
		*--ptr = Rep[num%base];
		num /= base;
	}

	return (ptr);
}
