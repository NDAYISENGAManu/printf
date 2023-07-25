#include "main.h"
/**
 * _printf - the formatted output conversion and print data.
 * @format: input of string.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuffer = 0;
	va_list argmts;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(argmts, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buff(buffer, ibuffer), free(buffer), va_end(argmts);
				return (-1);
			}
			else
			{	function = get_print(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buff(buffer, format[i], ibuffer), len++, i--;
				}
				else
				{
					len += function(argmts, buffer, ibuffer);
					i += print_funct(format, i + 1);
				}
			} i++;
		}
		else
			handle_buff(buffer, format[i], ibuffer), len++;
		for (ibuffer = len; ibuffer > 1024; ibuffer -= 1024)
			;
	}
	print_buff(buffer, ibuffer), free(buffer), va_end(argmts);
	return (len);
}
