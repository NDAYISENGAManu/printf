#include "main.h"

/**
 * handle_buff - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @ibuffer: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int handle_buff(char *buf, char c, unsigned int ibuffer)
{
	if (ibuffer == 1024)
	{
		print_buff(buf, ibuffer);
		ibuffer = 0;
	}
	buf[ibuffer] = c;
	ibuffer++;
	return (ibuffer);
}
