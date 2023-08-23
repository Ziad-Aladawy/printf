#include "main.h"

/**
 * print_char - prints character
 * @list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list list, params_t *p)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(list, int);

	if (p->minus)
		sum += _putchar(ch);
	while (pad++ < p->width)
		sum += _putchar(pad_char);
	if (!p->minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list list, params_t *p)
{
	long l;

	if (p->l_modifier)
		l = va_arg(list, long);
	else if (p->h_modifier)
		l = (short int)va_arg(list, int);
	else
		l = (int)va_arg(list, int);
	return (print_number(convert(l, 10, 0, p), p));
}

/**
 * print_string - prints string
 * @list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list list, params_t *p)
{
	char *str = va_arg(list, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, y = 0, x;

	(void)p;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	x = pad = _strlen(str);
	if (p->precision < pad)
		x = pad = p->precision;

	if (p->minus)
	{
		if (p->precision != UINT_MAX)
			for (y = 0; y < pad; y++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (x++ < p->width)
		sum += _putchar(pad_char);
	if (!p->minus)
	{
		if (p->precision != UINT_MAX)
			for (y = 0; y < pad; y++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list list, params_t *p)
{
	(void)list;
	(void)p;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list list, params_t *p)
{
	char *str = va_arg(list, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, p);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
