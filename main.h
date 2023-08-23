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
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define NULL_STRING "(null)"

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
        unsigned int h_modifier : 1;
        unsigned int l_modifier : 1;
}params_t;

/* specifiers format */
typedef struct format
{
        char *type;
        int (*f)(va_list, params_t *);
} format;



/* master function */
int _printf(const char *format, ...);

/* _puts.c */
int _puts(char *s);
int _putchar(int c);

/* print_functions.c */
int print_char(va_list list, params_t *p);
int print_string(va_list list, params_t *p);
int print_percent(va_list list, params_t *p);
int print_int(va_list list, params_t *p);
int print_S(va_list list, params_t *p);

/* converted_numbers.c */
int print_binary(va_list list, params_t *p);
int print_octal(va_list list, params_t *p);
int print_hex(va_list list, params_t *p);
int print_HEX(va_list list, params_t *p);

/* number.c */
int print_pointer(va_list list, params_t *params);
int print_unsigned(va_list list, params_t *params);
char *convert(long int num, int base, int flag, params_t *params);

/* manipulated.c */
int print_rev(va_list list, params_t *params);
int print_rot13(va_list list, params_t *params);
int print_from_to(char *start, char *stop, char *except);


/* specifier.c */
int (*get_specifier(char *s))(va_list list, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char*s, params_t *params, va_list list);
int get_flag(char *s, params_t *params);
int get_print_func(char *s, va_list list, params_t *params);


/* print_number.c */
int _strlen(char *s);
int _isdigit(int c);
int print_number(char *s, params_t *params);
int print_number_right_shift(char *s, params_t *params);
int print_number_left_shift(char *s, params_t *params);

/* percisions.c */
char *get_precision(char *p, params_t *params, va_list list);

/* params.c */
void init_params(params_t *params, va_list list);

#endif
