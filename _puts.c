#include <unistd.h>
#include "main.h"

int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return i;
}