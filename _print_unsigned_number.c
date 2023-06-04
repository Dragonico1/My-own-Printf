#include "main.h"
#include <unistd.h>

int print_unsigned_number(unsigned int n, char *buffer)
{
    int num_digits = 0;

    if (n == 0)
    {
        buffer[0] = '0';
        num_digits = 1;
    }
    else if (n / 10)
        num_digits += print_unsigned_number(n / 10, buffer);

    buffer[num_digits] = (n % 10) + '0';
    num_digits++;

    return num_digits;
}
