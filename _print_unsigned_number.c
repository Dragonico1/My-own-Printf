#include <unistd.h>
#include "main.h"

int print_unsigned_number(unsigned int n)
{
	int num_digits = 0;

	if (n == 0)
	{
		_putchar('0');
		num_digits++;
	}
	else if (n / 10)
		num_digits += print_unsigned_number(n / 10);

	_putchar((n % 10) + '0');
	num_digits++;

	return num_digits;
}
