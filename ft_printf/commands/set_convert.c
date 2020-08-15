/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 14:52:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_CONVERT_OPT		13
typedef struct		s_convert
{
	t_str 			code;
	int				(*print)(t_data *);
}					t_convert;

static const t_convert CONVERTS[MAX_CONVERT_OPT] = {
	(t_convert){(t_str){"c", 1u}, &convert_c},
	(t_convert){(t_str){"s", 1u}, &convert_s},
	(t_convert){(t_str){"p", 1u}, &convert_p},
	(t_convert){(t_str){"d", 1u}, &convert_d},
	(t_convert){(t_str){"i", 1u}, &convert_d},
	(t_convert){(t_str){"u", 1u}, &convert_u},
	(t_convert){(t_str){"x", 1u}, &convert_x},
	(t_convert){(t_str){"X", 1u}, &convert_up_x},
	(t_convert){(t_str){"%", 1u}, &convert_percent},
	(t_convert){(t_str){"n", 1u}, &convert_n},
	(t_convert){(t_str){"f", 1u}, &convert_f},
	(t_convert){(t_str){"g", 1u}, &convert_g},
	(t_convert){(t_str){"e", 1u}, &convert_e},
};

int set_convert(const char *code, t_data *datas){
	int i;

	i = MAX_CONVERT_OPT;
	while (--i >= 0)
	{
		if (ft_strncmp(CONVERTS[i].code.str, code, CONVERTS[i].code.size) == 0)
		{
			datas->cursor += CONVERTS[i].code.size;
			return (CONVERTS[i].print(datas));
		}
	}
	return (EXIT_CODE_NOT_FOUND);
}
