#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int y = 0;

	while (*s++)
		y++;
	return (y);
}

/**
 * print_number - prints a number with options
 * @s: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *s, params_t *params)
{
	unsigned int i = _strlen(s);
	int neg = (!params->unsign && *s == '-');

	if (!params->precision && *s == '0' && !s[1])
		s = "";
	if (neg)
	{
		s++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--s = '0';
	if (neg)
		*--s = '-';

	if (!params->minus)
		return (print_number_right_shift(s, params));
	else
		return (print_number_left_shift(s, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @s: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *s, params_t *params)
{
	unsigned int x = 0, neg, neg2, y = _strlen(s);
	char pad_char = ' ';

	if (params->zero && !params->minus)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *s == '-');
	if (neg && x < params->width && pad_char == '0' && !params->minus)
		s++;
	else
		neg = 0;
	if ((params->plus && !neg2) ||
		(!params->plus && params->space && !neg2))
		y++;
	if (neg && pad_char == '0')
		x += _putchar('-');
	if (params->plus && !neg2 && pad_char == '0' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus && params->space && !neg2 &&
		!params->unsign && params->zero)
		x += _putchar(' ');
	while (y++ < params->width)
		x += _putchar(pad_char);
	if (neg && pad_char == ' ')
		x += _putchar('-');
	if (params->plus && !neg2 && pad_char == ' ' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus && params->space && !neg2 &&
		!params->unsign && !params->zero)
		x += _putchar(' ');
	x += _puts(s);
	return (x);
}

/**
 * print_number_left_shift - prints a number with options
 * @s: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *s, params_t *params)
{
	unsigned int x = 0, neg, neg2, y = _strlen(s);
	char pad_char = ' ';

	if (params->zero && !params->minus)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *s == '-');
	if (neg && x < params->width && pad_char == '0' && !params->minus)
		s++;
	else
		neg = 0;

	if (params->plus && !neg2 && !params->unsign)
		x += _putchar('+'), y++;
	else if (params->space && !neg2 && !params->unsign)
		x += _putchar(' '), y++;
	x += _puts(s);
	while (y++ < params->width)
		x += _putchar(pad_char);
	return (x);
}

