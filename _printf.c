#include "main.h"

/**
 * _putchar - writes a character to stdout
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
 * @str: Pointer to the string to print
 *
 * Return: The number of characters printed
 */
static int print_string(char *str)
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
        count += print_number(num / 10);

    count += _putchar((num % 10) + '0');
    return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string containing directives
 *
 * Return: The number of characters printed (excluding the null byte),
 * or -1 on error (NULL format or stray '%' at end)
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
        {
            va_end(ap);
            return (-1);
        }

        if (*format == 'c')
            count += _putchar((char)va_arg(ap, int));
        else if (*format == 's')
            count += print_string(va_arg(ap, char *));
        else if (*format == '%')
            count += _putchar('%');
        else if (*format == 'd' || *format == 'i')
            count += print_number(va_arg(ap, int));
        else
        {
            count += _putchar('%');
            count += _putchar(*format);
        }
        format++;
    }

    va_end(ap);
    return (count);
}
