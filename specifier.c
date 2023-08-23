#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list list, params_t *params)
{
	format  specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_pointer},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int x = 0;

	while (specifiers[x].type)
	{
		if (*s == specifiers[x].type[0])
		{
			return (specifiers[x].f);
		}
		x++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @list: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list list, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(list, params));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int x = 0;

	switch (*s)
	{
		case '+':
			x = params->plus = 1;
			break;
		case ' ':
			x = params->space = 1;
			break;
		case '#':
			x = params->hashtag = 1;
			break;
		case '-':
			x = params->minus = 1;
			break;
		case '0':
			x = params->zero = 1;
			break;
	}
	return (x);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int x = 0;

	switch (*s)
	{
	case 'h':
		x = params->h_modifier = 1;
		break;
	case 'l':
		x = params->l_modifier = 1;
		break;
	}
	return (x);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list list)
{
	int x = 0;

	if (*s == '*')
	{
		x = va_arg(list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			x = x * 10 + (*s++ - '0');
	}
	params->width = x;
	return (s);
}
