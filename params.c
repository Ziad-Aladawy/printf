#include "main.h"

/**
 * init_params - clear struct
 * @params: struct
 * @list: argument pointer
*/

void init_params(params_t *params, va_list list)
{
	params->unsign = 0;

	params->plus = 0;
	params->minus = 0;
	params->space = 0;
	params->zero = 0;
	params->hashtag = 0;
	params->width = 0;
	params->percision = UNIT_MAX;
	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)list;
}
