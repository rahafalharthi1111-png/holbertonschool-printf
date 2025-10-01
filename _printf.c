#include "main.h"

/**
 * _putchar - Writes one character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string to stdout
 * @str: Pointer to string
 *
 * Return: Number of characters printed
 */
static int print_string(char *str)
{
	int count = 0;

	if (str == (char *)0)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * print_number - Prints an integer to stdout
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
static int print_number(int n)
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
		count += print_number((int)(num / 10));

	count += _putchar((char)((num % 10) + '0'));
	return (count);
}

/**
 * handle_specifier - Handles a single conversion specifier
 * @fmt: Pointer to current format char (advanced inside)
 * @ap:  va_list with arguments
 *
 * Return: Number of characters printed, or -1 on error
 */
static int handle_specifier(const char **fmt, va_list *ap)
{
	int printed = 0;

	if (**fmt == '\0')
		return (-1);

	if (**fmt == 'c')
		printed += _putchar((char)va_arg(*ap, int));
	else if (**fmt == 's')
		printed += print_string(va_arg(*ap, char *));
	else if (**fmt == '%')
		printed += _putchar('%');
	else if (**fmt == 'd' || **fmt == 'i')
		printed += print_number(va_arg(*ap, int));
	else
	{
		printed += _putchar('%');
		printed += _putchar(**fmt);
	}

	(*fmt)++;
	return (printed);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string
 *
 * Return: Number of chars printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	if (format == (const char *)0)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
			format++;
			continue;
		}

		format++; /* skip '%' */

		if (*format == '\0')
		{
			va_end(ap);
			return (-1);
		}

		count += handle_specifier(&format, &ap);
		if (count < 0)
		{
			va_end(ap);
			return (-1);
		}
	}

	va_end(ap);
	return (count);
}
