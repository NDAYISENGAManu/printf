#include "main.h"
#include <stdio.h>
/**
 * print_addrss - prints the address of an input variable
 * @argmts: input address.
 * @buf: buffer pointer.
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_addrss(va_list argmts, char *buf, unsigned int ibuffer)
{
    void *add;
    long int int_input;
    int i, count, first_digit, isnegative;
    char *hexadecimal, *binary;
    char nill[] = "(nil)";

    add = (va_arg(argmts, void *));
    if (add == NULL)
    {
        for (i = 0; nill[i]; i++)
            ibuffer = handle_buff(buf, nill[i], ibuffer);
        return (5);
    }
    int_input = (intptr_t)add;
    isnegative = 0;
    if (int_input < 0)
    {
        int_input = (int_input * -1) - 1;
        isnegative = 1;
    }
    binary = malloc(sizeof(char) * (64 + 1));
    binary = binary_array(binary, int_input, isnegative, 64);
    hexadecimal = malloc(sizeof(char) * (16 + 1));
    hexadecimal = hexag_array(binary, hexadecimal, 0, 16);
    ibuffer = handle_buff(buf, '0', ibuffer);
    ibuffer = handle_buff(buf, 'x', ibuffer);
    for (first_digit = i = count = 0; hexadecimal[i]; i++)
    {
        if (hexadecimal[i] != '0' && first_digit == 0)
            first_digit = 1;
        if (first_digit)
        {
            ibuffer = handle_buff(buf, hexadecimal[i], ibuffer);
            count++;
        }
    }
    free(binary);
    free(hexadecimal);
    return (count + 2);
}

/**
 * print_charc - writes the character c to stdout
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int print_charc(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
    handle_buff(buf, '%', i);

    return (1);
}

/**
 * print_chrs - writes the character c to stdout
 * @argmts: input char
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: On success 1.
 */
int print_chrs(va_list argmts, char *buf, unsigned int ibuffer)
{
    char c;

    c = va_arg(argmts, int);
    handle_buff(buf, c, ibuffer);

    return (1);
}
