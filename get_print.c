#include "main.h"
/**
 * get_print - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_print(const char *s, int index))(va_list, char *, unsigned int)
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
		{" i", print_space_int},
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
		{" +d", print_space_int},
		{"+ i", print_space_int},
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
	return (pr[i].f);
}
