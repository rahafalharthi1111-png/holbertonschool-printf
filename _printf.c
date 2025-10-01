/*
 * File: _printf.c
 * Description: Helpers used by _printf (string and number printers).
 * Contains implementations of print_string and print_number.
 */

#include "main.h"

/**
 * print_string - Prints a string to stdout
 * @str: Pointer to the string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
		count += _putchar(*str++);

	return (count);
}

/**
 * print_number - Prints an integer to stdout
 * @n: Integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

