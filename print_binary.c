#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    int started = 0;

    if (n == 0)
        return (_putchar('0'));

    while (mask)
    {
        if (n & mask)
        {
            _putchar('1');
            count++;
            started = 1;
        }
        else if (started)
        {
            _putchar('0');
            count++;
        }
        mask >>= 1;
    }

    return (count);
}
