#include "main.h"
/**
 * convert - convert number to proper format
 * @num: number given
 * Return: the number
 */

char *negative(unsigned int num)
{
	if (num < 0)
	{
		num = -num;
		putchar('-');
	}

	return (num);
}
