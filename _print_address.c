#include "main.h"
#include <unistd.h>

int print_address(unsigned long long n, char *buffer)
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

    for (i = num_digits - 1; i >= 0; i--)
    {
        buffer[i] = hex_digits[n % 16];
        n /= 16;
    }

    return num_digits;
}
