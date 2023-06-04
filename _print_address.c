#include <stdarg.h>
#include <stddef.h>
#include "main.h"

int print_address(unsigned long long n)
{
    char hex_digits[] = "0123456789abcdef";
    int num_digits = 0;
    unsigned long long temp = n;
    int i;

    while (temp > 0)
    {
        temp /= 16;
        num_digits++;
    }

    char hex_num[num_digits];

    for (i = num_digits - 1; i >= 0; i--)
    {
        hex_num[i] = hex_digits[n % 16];
        n /= 16;
    }

    for (i = 0; i < num_digits; i++)
    {
        _putchar(hex_num[i]);
    }

    return num_digits;
}
