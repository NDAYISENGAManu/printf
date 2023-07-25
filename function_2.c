#include "main.h"

/**
 * print_binry - prints decimal in binary
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_binry(va_list argmts, char *buf, unsigned int ibuffer)
{
    int int_input, count, i, first_one, isnegative;
    char *binary;

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
    first_one = 0;
    for (count = i = 0; binary[i]; i++)
    {
        if (first_one == 0 && binary[i] == '1')
            first_one = 1;
        if (first_one == 1)
        {
            ibuffer = handle_buff(buf, binary[i], ibuffer);
            count++;
        }
    }
    free(binary);
    return (count);
}

/**
 * print_buff - prints buffer
 * @buf: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buff(char *buf, unsigned int nbuf)
{
    return (write(1, buf, nbuf));
}

/**
 * print_funct - returns the amount of identifiers.
 * @s: argmts indentifier
 * @index: index of argmts identifier.
 * Return: amounts of identifier.
 */
int print_funct(const char *s, int index)
{
    print_t pr[] = {
        {"c", print_chrs},
        {"s", print_strg},
        {"i", print_intg},
        {"d", print_intg},
        {"b", print_binry},
        {"u", print_untg},
        {"o", print_octg},
        {"x", print_hexg},
        {"X", print_upg},
        {"S", print_usrs},
        {"p", print_addrss},
        {"li", print_ln_intg},
        {"ld", print_ln_intg},
        {"lu", print_ln_untg},
        {"lo", print_ln_octg},
        {"lx", print_ln_hex},
        {"lX", print_ln_upg},
        {"hi", print_hx_int},
        {"hd", print_hx_int},
        {"hu", print_hx_untg},
        {"ho", print_hx_octg},
        {"hx", print_hx_hexg},
        {"hX", print_hx_upg},
        {"#o", print_n_oct},
        {"#x", print_n_hex},
        {"#X", print_n_upg},
        {"#i", print_intg},
        {"#d", print_intg},
        {"#u", print_untg},
        {"+i", print_n_int},
        {"+d", print_n_int},
        {"+u", print_untg},
        {"+o", print_octg},
        {"+x", print_hexg},
        {"+X", print_upg},
        {" i", print_n_int},
        {" d", print_n_int},
        {" u", print_untg},
        {" o", print_octg},
        {" x", print_hexg},
        {" X", print_upg},
        {"R", print_rts},
        {"r", print_revrs},
        {"%", print_charc},
        {"l", print_charc},
        {"h", print_charc},
        {" +i", print_n_int},
        {" +d", print_n_int},
        {"+ i", print_n_int},
        {"+ d", print_n_int},
        {" %", print_charc},
        {NULL, NULL},
    };
    int i = 0, j = 0, first_index;

    first_index = index;
    while (pr[i].type_arg)
    {
        if (s[index] == pr[i].type_arg[j])
        {
            if (pr[i].type_arg[j + 1] != '\0')
                index++, j++;
            else
                break;
        }
        else
        {
            j = 0;
            i++;
            index = first_index;
        }
    }
    return (j);
}

/**
 * print_hexg - prints a decimal in hexadecimal
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_hexg(va_list argmts, char *buf, unsigned int ibuffer)
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
    return (count);
}

/**
 * print_intg - prints an integer
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_intg(va_list argmts, char *buf, unsigned int ibuffer)
{
    int int_input;
    unsigned int int_in, int_temp, i, div, isneg;

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
