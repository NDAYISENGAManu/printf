#include "main.h"

/**
 * print_hx_hexg - prints a short decimal in hexadecimal
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_hx_hexg(va_list argmts, char *buf, unsigned int ibuffer)
{
    short int int_input, i, isnegative, count, first_digit;
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

    binary = malloc(sizeof(char) * (16 + 1));
    binary = binary_array(binary, int_input, isnegative, 16);
    hexadecimal = malloc(sizeof(char) * (4 + 1));
    hexadecimal = hexag_array(binary, hexadecimal, 0, 4);
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
    return (count);
}

/**
 * print_hx_int - prints a short integer
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_hx_int(va_list argmts, char *buf, unsigned int ibuffer)
{
    short int int_input;
    unsigned short int int_in, int_temp, i, div, isneg;

    int_input = va_arg(argmts, int);
    isneg = 0;
    if (int_input < 0)
    {
        int_in = int_input * -1;
        ibuffer = handle_buff(buf, '-', ibuffer);
        isneg = 1;
    }
    else
    {
        int_in = int_input;
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
    return (i + isneg);
}

/**
 * print_hx_octg - prints long decimal number in octal
 * @argmts: input number
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_hx_octg(va_list argmts, char *buf, unsigned int ibuffer)
{
    short int int_input, i, isnegative, count, first_digit;
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

    binary = malloc(sizeof(char) * (16 + 1));
    binary = binary_array(binary, int_input, isnegative, 16);
    octal = malloc(sizeof(char) * (6 + 1));
    octal = shrt_oct_array(binary, octal);
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

/**
 * print_hx_untg - prints a short unsigned integer
 * @argmts: number to print
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_hx_untg(va_list argmts, char *buf, unsigned int ibuffer)
{
    unsigned short int int_in, int_temp, i, div;

    int_in = va_arg(argmts, unsigned int);

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
    return (i);
}

/**
 * print_hx_upg - prints a short decimal in hexadecimal
 * @argmts: The character to print
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_hx_upg(va_list argmts, char *buf, unsigned int ibuffer)
{
    short int int_input, i, isnegative, count, first_digit;
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

    binary = malloc(sizeof(char) * (16 + 1));
    binary = binary_array(binary, int_input, isnegative, 16);
    hexadecimal = malloc(sizeof(char) * (4 + 1));
    hexadecimal = hexag_array(binary, hexadecimal, 1, 4);

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

    return (count);
}

