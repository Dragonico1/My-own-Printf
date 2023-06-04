#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_unsigned_number(unsigned int n);
int print_number(int n);
int count_unsigned_digits(unsigned int n);
int print_unsigned_hex(unsigned int n, int uppercase);
int print_address(unsigned long long n);
int print_binary(unsigned int n);
int print_unsigned_octal(unsigned int n);
int write_buffer(char *buffer, int buffer_index);

#endif