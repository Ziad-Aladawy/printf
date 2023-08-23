#include "main.h"

/**
 * print_from_to - prints a range
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: sum
*/
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints reversed string
 * @list: string
 * @params: parameters struct
 * Return: sum
*/
int print_rev(va_list list, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(list, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}


/**
 * print_rot13 - print string with rot13 (used it in a task before)
 * @list: string
 * @params: parameters struct
 * Return: sum
*/
int print_rot13(va_list list, params_t *params)
{
	int i = 0, index = 0;
	int cnt = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(list, char *);
	(void)params;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			cnt += _putchar(arr[index]);
		}
		else
			cnt += _putchar(arr[index]);
		i++;
	}
	return (cnt);
}
