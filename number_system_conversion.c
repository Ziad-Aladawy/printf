#include "main.h"

/**
 * print_hex - prints hex numbers in lowercase
 * @list: variadic argument pointer
 * @p: the parameters struct
 *
 * Return: bytes count
 */
int print_hex(va_list list, params_t *p)
{
	unsigned long l;
	int x = 0;
	char *str;

	if (p->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (p->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, p);
	if (p->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	p->unsign = 1;
	return (x += print_number(str, p));
}

/**
 * print_HEX - prints hex numbers in uppercase
 * @list: the variadic argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list list, params_t *p)
{
	unsigned long l;
	int x = 0;
	char *str;

	if (p->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (p->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, p);
	if (p->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	p->unsign = 1;
	return (x += print_number(str, p));
}
/**
 * print_binary - prints binary number
 * @list: the variadic argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list list, params_t *p)
{
	unsigned int n = va_arg(list, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, p);
	int x = 0;

	if (p->hashtag_flag && n)
		*--str = '0';
	p->unsign = 1;
	return (x += print_number(str, p));
}

/**
 * print_octal - prints octal numbers
 * @list: the variadic argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list list, params_t *p)
{
	unsigned long l;
	char *str;
	int x = 0;

	if (p->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (p->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, p);

	if (p->hashtag_flag && l)
		*--str = '0';
	p->unsign = 1;
	return (x += print_number(str, p));
}
