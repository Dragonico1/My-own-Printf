#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_unsigned_octal(unsigned int n, char *buffer);
int print_unsigned_hex(unsigned int n, int uppercase, char *buffer);
int print_address(unsigned long long n, char *buffer);
int print_number(int n, char *buffer);
int print_unsigned_number(unsigned int n, char *buffer);
int print_binary(unsigned int n, char *buffer);
void print_special_string(const char *str, char *buffer, int *buffer_index, int *len);



#endif