/*
 * File: functions.c
 * Description: Helper functions used by _printf
 * Contains implementations of print_string and print_number.
 */

#include "main.h"
#include<stddef.h>
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
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

