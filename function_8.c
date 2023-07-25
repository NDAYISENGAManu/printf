#include "main.h"

/**
 * print_strg - writes the string to stdout
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: On success 1.
 */
int print_strg(va_list argmts, char *buf, unsigned int ibuffer)
{
    char *str;
    unsigned int i;
    char nill[] = "(null)";

    str = va_arg(argmts, char *);
    if (str == NULL)
    {
        for (i = 0; nill[i]; i++)
            ibuffer = handle_buff(buf, nill[i], ibuffer);
        return (6);
    }
    for (i = 0; str[i]; i++)
        ibuffer = handle_buff(buf, str[i], ibuffer);
    return (i);
}

/**
 * print_untg - prints an unsigned int
 * @argmts: number to print
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_untg(va_list argmts, char *buf, unsigned int ibuffer)
{
    unsigned int int_in, int_temp, i, div;

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
 * print_upg - prints a decimal in hexadecimal
 * @argmts: The character to print
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_upg(va_list argmts, char *buf, unsigned int ibuffer)
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
    return (count);
}

/**
 * print_usrs - prints a string and values of
 * non-printed chars
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_usrs(va_list argmts, char *buf, unsigned int ibuffer)
{
    unsigned char *str;
    char *hexadecimal, *binary;
    unsigned int i, sum, op;

    str = va_arg(argmts, unsigned char *);
    binary = malloc(sizeof(char) * (32 + 1));
    hexadecimal = malloc(sizeof(char) * (8 + 1));
    for (sum = i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            ibuffer = handle_buff(buf, '\\', ibuffer);
            ibuffer = handle_buff(buf, 'x', ibuffer);
            op = str[i];
            binary = binary_array(binary, op, 0, 32);
            hexadecimal = hexag_array(binary, hexadecimal, 1, 8);
            ibuffer = handle_buff(buf, hexadecimal[6], ibuffer);
            ibuffer = handle_buff(buf, hexadecimal[7], ibuffer);
            sum += 3;
        }
        else
            ibuffer = handle_buff(buf, str[i], ibuffer);
    }
    free(binary);
    free(hexadecimal);
    return (i + sum);
}
