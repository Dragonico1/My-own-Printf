#include <stdarg.h>
#include <stddef.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					len++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					len += _puts(str);
					break;
                case 'o':
					len += print_unsigned_octal(va_arg(args, unsigned int));
					break;
                case 'x':
					len += print_unsigned_hex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					len += print_unsigned_hex(va_arg(args, unsigned int), 1);
					break;
				case '%':
					_putchar('%');
					len++;
					break;
				case 'p':
				void *ptr = va_arg(args, void *);
				len += _puts("0x");
				len += print_address((unsigned long long)ptr);
				break;
				case 'd':
				case 'i':
					len += print_number(va_arg(args, int));
					break;
				case 'u':
					len += print_unsigned_number(va_arg(args, unsigned int));
					break;

				case 'b':
					len += print_binary(va_arg(args, unsigned int));
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					len += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}

		i++;
	}

	va_end(args);

	return len;
}
