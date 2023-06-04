#include <unistd.h>
#include "main.h"

int count_unsigned_digits(unsigned int n)
{
	int count = 0;

	if (n == 0)
		return 1;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return count;
}