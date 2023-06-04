#include "main.h"
#include <unistd.h>
#include <stdbool.h>

int print_unsigned_hex(unsigned int n, int uppercase, char *buffer)
{
    char hex_digits[] = "0123456789abcdef";
    int num_digits = 0;
    unsigned int temp = n;
    int i;

    if (n == 0)
    {
        buffer[0] = '0';
        num_digits = 1;
    }
    else
    {
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
            if (uppercase)
                buffer[i] = hex_num[i] >= 'a' && hex_num[i] <= 'f' ? hex_num[i] - 32 : hex_num[i];
            else
                buffer[i] = hex_num[i];
        }
    }

    return num_digits;
}
