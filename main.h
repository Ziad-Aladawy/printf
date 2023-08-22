#ifndef MAIN
#define MAIN

/* libraries */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/* before parameters */
#define PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* master function */
int _printf(const char *format, ...);

/* based on specifier */
int print_char(va_list list, params_t *p);
int print_string(va_list list, params_t *p);
int print_percent(va_list list, params_t *p);
int print_int(va_list list, params_t *p);
int print_S(va_list list, params_t *p);

/* converted numbers */
int print_binary(va_list list, params_t *p);
int print_octal(va_list list, params_t *p);
int print_hex(va_list list, params_t *p);
int print_HEX(va_list list, params_t *p);

/* no title */
int print_pointer(va_list list, params_t *p);
int print_unsigned(va_list list, params_t *p);

/* manipulated */
int print_rev(va_list list, params_t *p);
int print_rot13(va_list list, params_t *p);


/* parameters */

/**
 * struct parameters - to handle the parameters before specifier
 * @unsign: flag for unsigned value
 * @plus: plus flag
 * @minus: minus flag
 * @space: space flag
 * @hashtag: hashtag flag
 * @zero: zero flag
 * @width: field width
 * @precision: field precision
*/
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus : 1;
	unsigned int minus : 1;
	unsigned int space : 1;
	unsigned int hashtag : 1;
	unsigned int zero : 1;
	unsigned int width : 1;
	unsigned int precision : 1;

}params_t;

/* specifiers format */
typedef struct format
{
	char *type;
	int (*f)(va_list, params_t *);
} format;

#endif
