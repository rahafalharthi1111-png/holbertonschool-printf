#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int print_number(int n);
int print_unsigned(unsigned int n);
int _octal(unsigned int n);
int print_hex(unsigned int n, int upperCase);
#endif
