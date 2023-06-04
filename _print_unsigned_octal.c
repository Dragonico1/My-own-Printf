#include <stdarg.h>
#include <stddef.h>
#include "main.h"

int print_unsigned_octal(unsigned int n)
{
	int num_digits = 0;

	if (n == 0)
	{
		_putchar('0');
		num_digits++;
	}
	else if (n / 8)
		num_digits += print_unsigned_octal(n / 8);

	_putchar((n % 8) + '0');
	num_digits++;

	return num_digits;
}
