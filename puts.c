#include "main.h"

/**
 * _puts: print string
 * @s: string
 * Return: len
*/
int _puts(char *s)
{
	char *a = s;

	while (*s)
		_putchar(*str++);
	return (s - a);
}

/**
 * _putchar: print char
 * @c: char
 * Return: 1 success, -1 error
*/

int _putchar(int c)
{
	static int i;
	static char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;

	return (1)
}

