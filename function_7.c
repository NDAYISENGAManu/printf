#include "main.h"

/**
 * print_revrs - writes the str in reverse
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int print_revrs(va_list argmts, char *buf, unsigned int ibuffer)
{
    char *str;
    unsigned int i;
    int j = 0;
    char nill[] = "(llun)";

    str = va_arg(argmts, char *);
    if (str == NULL)
    {
        for (i = 0; nill[i]; i++)
            ibuffer = handle_buff(buf, nill[i], ibuffer);
        return (6);
    }
    for (i = 0; str[i]; i++)
        ;
    j = i - 1;
    for (; j >= 0; j--)
    {
        ibuffer = handle_buff(buf, str[j], ibuffer);
    }
    return (i);
}

/**
 * print_rts - writes the str in ROT16
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */

int print_rts(va_list argmts, char *buf, unsigned int ibuffer)
{
    char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    char *str;
    unsigned int i, j, k;
    char nill[] = "(avyy)";

    str = va_arg(argmts, char *);
    if (str == NULL)
    {
        for (i = 0; nill[i]; i++)
            ibuffer = handle_buff(buf, nill[i], ibuffer);
        return (6);
    }
    for (i = 0; str[i]; i++)
    {
        for (k = j = 0; alf[j]; j++)
        {
            if (str[i] == alf[j])
            {
                k = 1;
                ibuffer = handle_buff(buf, rot[j], ibuffer);
                break;
            }
        }
        if (k == 0)
            ibuffer = handle_buff(buf, str[i], ibuffer);
    }
    return (i);
}

/**
 * print_n_int - prints int begining with space
 * @argmts: input string
 * @buf: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_space_int(va_list argmts, char *buf, unsigned int ibuffer)
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
        ibuffer = handle_buff(buf, ' ', ibuffer);
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
