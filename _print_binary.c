#include <stdarg.h>
#include "main.h"

int print_binary(unsigned int n)
{
	int num_digits = 0;

	if (n / 2)
		num_digits += print_binary(n / 2);

	_putchar((n % 2) + '0');
	num_digits++;

	return num_digits;
}