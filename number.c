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

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
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
 * print_unsigned - print unsigned numbers
 * @list: argument pointer
 * @params: parameter struct
 * Return: sum
*/
int print_unsigned(va_list list, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_pointer - print address
 * @list: pointer
 * @params: parameter struct
 * Return: sum
*/
int print_pointer(va_list list, params_t *params)
{
	unsigned long int n = va_arg(list, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));
	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
