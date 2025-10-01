#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string containing directives
 *
 * Return: The number of characters printed (excluding the null byte),
 * or -1 if an error occurs
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format++);
			continue;
		}

		format++; /* skip '%' */

		if (*format == '\0')
			break;

		if (*format == 'c')
			count += _putchar(va_arg(ap, int));
		else if (*format == 's')
			count += print_string(va_arg(ap, char *));
		else if (*format == '%')
			count += _putchar('%');
		else if (*format == 'd' || *format == 'i')
			count += print_number(va_arg(ap, int));
		else
		{
			/* Unknown specifier: print it verbatim */
			count += _putchar('%');
			count += _putchar(*format);
		}
		format++;
	}

	va_end(ap);
	return (count);
}
