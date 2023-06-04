#include <stdarg.h>
#include <stddef.h>
#include "main.h"

int print_unsigned_hex(unsigned int n, int uppercase)
{
	char hex_digits[] = "0123456789abcdef";
	int num_digits = 0;
	unsigned int temp = n;
	int i;

	if (n == 0)
	{
		_putchar('0');
		num_digits++;
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
				_putchar(hex_num[i] >= 'a' && hex_num[i] <= 'f' ? hex_num[i] - 32 : hex_num[i]);
			else
				_putchar(hex_num[i]);
		}
	}

	return num_digits;
}