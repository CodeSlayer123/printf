#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

int _putchar(char c);
void output(char *s);
int _printf(const char *format, ...);
char *convert(unsigned int num, int base);

#endif
