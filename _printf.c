#include <stdarg.h>
#include <stddef.h>
#include "main.h"
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;
	char *str;

	va_start(args, format);

	char buffer[1024];
	int buffer_index = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					int c = va_arg(args, int);
					buffer[buffer_index++] = (char)c;
					len++;
					break;
				}
				case 's':
				{
					str = va_arg(args, char *);
					if (str == NULL)
    				{
    					str = "(null)";
    				}
					int str_len = 0;
					while (str[str_len] != '\0')
    				{
    					str_len++;
    				}
					for (int j = 0; j < str_len; j++)
					{
						buffer[buffer_index++] = str[j];
					}
					len += str_len;
					break;
				}
                case 'o':
				{
					int digits = print_unsigned_octal(va_arg(args, unsigned int), buffer + buffer_index);
					buffer_index += digits;
					len += digits;
					break;
				}
                case 'x':
				{
					int digits = print_unsigned_hex(va_arg(args, unsigned int), 0, buffer + buffer_index);
					buffer_index += digits;
					len += digits;
					break;
				}
				case 'X':
				{
					int digits = print_unsigned_hex(va_arg(args, unsigned int), 1, buffer + buffer_index);
					buffer_index += digits;
					len += digits;
					break;
				}
				case '%':
					buffer[buffer_index++] = '%';
					len++;
					break;
				case 'p':
				{
					void *ptr = va_arg(args, void *);
					buffer[buffer_index++] = '0';
					buffer[buffer_index++] = 'x';
					int digits = print_address((unsigned long long)ptr, buffer + buffer_index);
					buffer_index += digits;
					len += (digits + 2);
					break;
				}
				case 'd':
				{
					int digits = print_number(va_arg(args, int), buffer + buffer_index);
					buffer_index += digits;
					len += digits;
					break;
				}
				case 'i':
				{
					int digits = print_number(va_arg(args, int), buffer + buffer_index);
					buffer_index += digits;
					len += digits;
					break;
				}
				case 'u':
				{
					int digits = print_unsigned_number(va_arg(args, unsigned int), buffer + buffer_index);
					buffer_index += digits;
					len += digits;
					break;
				}
				case 'b':
				{
					int digits = print_binary(va_arg(args, unsigned int), buffer + buffer_index);
					buffer_index += digits;
					len += digits;
					break;
				}
				default:
					buffer[buffer_index++] = '%';
					buffer[buffer_index++] = format[i];
					len += 2;
					break;
			}
		}
		else
		{
			buffer[buffer_index++] = format[i];
			len++;
		}

		i++;

		if (buffer_index >= 1024 - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
	}

	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
	}

	va_end(args);

	return len;
}
