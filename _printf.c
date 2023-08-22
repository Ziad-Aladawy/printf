#include "main.h"

/**
 * _printf: produces output according to a format.
 * @format: is a character string.
 * Return: : the number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list list;
	int size = 0;

	if (format == NULL)
		return (-1);
	for (; format[size] != 0; size++)
		;
}
