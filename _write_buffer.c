#include <unistd.h>
#include "main.h"

int write_buffer(char *buffer, int buffer_index)
{
	return write(1, buffer, buffer_index);
}
