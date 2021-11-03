#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

char *_strrev(char *str);
char *_itoa(int i, char *strout, int base);
int _putchar(char c);
void output(char *s);
int _printf(const char *format, ...);

#endif
