#include "main.h"

/**
 * convert - converter itoa
 * @num: number
 * @base: base
 * @flag: flag
 * @params: parameters struct
 * Return: string
*/
char *convert(long int num, int base, int flag, params_t *params)
{
	static char *array, buffer[50];
	char sign = 0, *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * */
