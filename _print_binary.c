#include "main.h"
#include <unistd.h>

int print_binary(unsigned int n, char *buffer)
{
    int num_digits = 0;

    if (n == 0)
    {
        buffer[0] = '0';
        num_digits = 1;
    }
    else if (n / 2)
        num_digits += print_binary(n / 2, buffer);

    buffer[num_digits] = (n % 2) + '0';
    num_digits++;

    return num_digits;
}
