#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int print_charc(va_list __attribute__((unused)), char *, unsigned int);
int print_chrs(va_list argmts, char *buf, unsigned int ibuffer);
int print_strg(va_list argmts, char *buf, unsigned int ibuffer);
int print_intg(va_list argmts, char *buf, unsigned int ibuffer);
int print_binry(va_list argmts, char *buf, unsigned int ibuffer);
int print_untg(va_list argmts, char *buf, unsigned int ibuffer);
int print_octg(va_list argmts, char *buf, unsigned int ibuffer);
int print_hexg(va_list argmts, char *buf, unsigned int ibuffer);
int print_upg(va_list argmts, char *buf, unsigned int ibuffer);
int print_usrs(va_list argmts, char *buf, unsigned int ibuffer);
int print_addrss(va_list argmts, char *buf, unsigned int ibuffer);
int print_revrs(va_list argmts, char *buf, unsigned int ibuffer);
int print_rts(va_list argmts, char *buf, unsigned int ibuffer);
int print_ln_intg(va_list argmts, char *buf, unsigned int ibuffer);
int print_ln_untg(va_list argmts, char *buf, unsigned int ibuffer);
int print_ln_octg(va_list argmts, char *buf, unsigned int ibuffer);
int print_ln_hex(va_list argmts, char *buf, unsigned int ibuffer);
int print_ln_upg(va_list argmts, char *buf, unsigned int ibuffer);
int print_hx_int(va_list argmts, char *buf, unsigned int ibuffer);
int print_hx_untg(va_list argmts, char *buf, unsigned int ibuffer);
int print_hx_octg(va_list argmts, char *buf, unsigned int ibuffer);
int print_hx_hexg(va_list argmts, char *buf, unsigned int ibuffer);
int print_hx_upg(va_list argmts, char *buf, unsigned int ibuffer);
int print_n_int(va_list argmts, char *buf, unsigned int ibuffer);
int print_n_oct(va_list argmts, char *buf, unsigned int ibuffer);
int print_n_hex(va_list argmts, char *buf, unsigned int ibuffer);
int print_n_upg(va_list argmts, char *buf, unsigned int ibuffer);
int print_space_int(va_list argmts, char *buf, unsigned int ibuffer);
int (*get_print(const char *s, int index))(va_list, char *, unsigned int);
int print_funct(const char *s, int index);
unsigned int handle_buff(char *buf, char c, unsigned int ibuffer);
int print_buff(char *buf, unsigned int nbuf);
char *binary_array(char *binary, long int int_in, int isneg, int limit);
char *oct_array(char *binr, char *oct);
char *lng_oct_array(char *binr, char *oct);
char *shrt_oct_array(char *binr, char *oct);
char *hexag_array(char *binr, char *hex, int isupp, int limit);

#endif
