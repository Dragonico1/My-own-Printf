#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

void print_special_string(const char *str, char *buffer, int *buffer_index, int *len) 
{
    if (str == NULL) 
    {
        str = "(null)";
    }

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] < 32 || str[i] >= 127) 
        {
            buffer[(*buffer_index)++] = '\\';
            buffer[(*buffer_index)++] = 'x';
            char hex[3];
            print_unsigned_hex((unsigned int)str[i], 0, buffer);
            buffer[(*buffer_index)++] = hex[0];
            buffer[(*buffer_index)++] = hex[1];
            (*len) += 4;
        } 
        else 
        {
            buffer[(*buffer_index)++] = str[i];
            (*len)++;
        }
    }
}