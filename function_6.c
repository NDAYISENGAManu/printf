#include "main.h"

/**
 * print_n_hex - print number in hex begining with zero
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_n_hex(va_list argmts, char *buf, unsigned int ibuffer)
{
    int int_input, i, isnegative, count, first_digit;
    char *hexadecimal, *binary;

    int_input = va_arg(argmts, int);
    isnegative = 0;
    if (int_input == 0)
    {
        ibuffer = handle_buff(buf, '0', ibuffer);
        return (1);
    }
    if (int_input < 0)
    {
        int_input = (int_input * -1) - 1;
        isnegative = 1;
    }
    ibuffer = handle_buff(buf, '0', ibuffer);
    ibuffer = handle_buff(buf, 'x', ibuffer);
    binary = malloc(sizeof(char) * (32 + 1));
    binary = binary_array(binary, int_input, isnegative, 32);
    hexadecimal = malloc(sizeof(char) * (8 + 1));
    hexadecimal = hexag_array(binary, hexadecimal, 0, 8);
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
 * print_n_int - print integer with plus symbol
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_n_int(va_list argmts, char *buf, unsigned int ibuffer)
{
    int int_input;
    unsigned int int_in, int_temp, i, div;

    int_input = va_arg(argmts, int);
    if (int_input < 0)
    {
        int_in = int_input * -1;
        ibuffer = handle_buff(buf, '-', ibuffer);
    }
    else
    {
        int_in = int_input;
        ibuffer = handle_buff(buf, '+', ibuffer);
    }
    int_temp = int_in;
    div = 1;
    while (int_temp > 9)
    {
        div *= 10;
        int_temp /= 10;
    }
    for (i = 0; div > 0; div /= 10, i++)
    {
        ibuffer = handle_buff(buf, ((int_in / div) % 10) + '0', ibuffer);
    }
    return (i + 1);
}

/**
 * print_n_oct - print the number in octal begining with zero
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_n_oct(va_list argmts, char *buf, unsigned int ibuffer)
{
    int int_input, i, isnegative, count, first_digit;
    char *octal, *binary;

    int_input = va_arg(argmts, int);
    isnegative = 0;
    if (int_input == 0)
    {
        ibuffer = handle_buff(buf, '0', ibuffer);
        return (1);
    }
    if (int_input < 0)
    {
        int_input = (int_input * -1) - 1;
        isnegative = 1;
    }
    ibuffer = handle_buff(buf, '0', ibuffer);
    binary = malloc(sizeof(char) * (32 + 1));
    binary = binary_array(binary, int_input, isnegative, 32);
    octal = malloc(sizeof(char) * (11 + 1));
    octal = oct_array(binary, octal);
    for (first_digit = i = count = 0; octal[i]; i++)
    {
        if (octal[i] != '0' && first_digit == 0)
            first_digit = 1;
        if (first_digit)
        {
            ibuffer = handle_buff(buf, octal[i], ibuffer);
            count++;
        }
    }
    free(binary);
    free(octal);
    return (count + 1);
}

/**
 * print_n_upg - prints number in uppercase hex
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_n_upg(va_list argmts, char *buf, unsigned int ibuffer)
{
    int int_input, i, isnegative, count, first_digit;
    char *hexadecimal, *binary;

    int_input = va_arg(argmts, int);
    isnegative = 0;
    if (int_input == 0)
    {
        ibuffer = handle_buff(buf, '0', ibuffer);
        return (1);
    }
    if (int_input < 0)
    {
        int_input = (int_input * -1) - 1;
        isnegative = 1;
    }
    ibuffer = handle_buff(buf, '0', ibuffer);
    ibuffer = handle_buff(buf, 'X', ibuffer);
    binary = malloc(sizeof(char) * (32 + 1));
    binary = binary_array(binary, int_input, isnegative, 32);
    hexadecimal = malloc(sizeof(char) * (8 + 1));
    hexadecimal = hexag_array(binary, hexadecimal, 1, 8);
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
 * print_octg - prints decimal number in octal
 * @argmts: input number
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_octg(va_list argmts, char *buf, unsigned int ibuffer)
{
    int int_input, i, isnegative, count, first_digit;
    char *octal, *binary;

    int_input = va_arg(argmts, int);
    isnegative = 0;
    if (int_input == 0)
    {
        ibuffer = handle_buff(buf, '0', ibuffer);
        return (1);
    }
    if (int_input < 0)
    {
        int_input = (int_input * -1) - 1;
        isnegative = 1;
    }
    binary = malloc(sizeof(char) * (32 + 1));
    binary = binary_array(binary, int_input, isnegative, 32);
    octal = malloc(sizeof(char) * (11 + 1));
    octal = oct_array(binary, octal);
    for (first_digit = i = count = 0; octal[i]; i++)
    {
        if (octal[i] != '0' && first_digit == 0)
            first_digit = 1;
        if (first_digit)
        {
            ibuffer = handle_buff(buf, octal[i], ibuffer);
            count++;
        }
    }
    free(binary);
    free(octal);
    return (count);
}
