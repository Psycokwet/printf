/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_or_fieldwith.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/14 11:06:01 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	set_precision_or_fieldwith_int(t_data *datas, const int value,
			const int sign)
{
	if (datas->active_flags & FT_PF_FLAG_PRECISION)
	{
		if (sign >= 0 && !(datas->unauthorized_flags & FT_PF_FLAG_PRECISION))
			datas->precision = value;
	}
	else
	{
		datas->active_flags |= FT_PF_FLAG_FIELD_WIDTH;
		datas->field_width = value;
		if (sign < 0)
			datas->active_flags |= FT_PF_NEG_FIELD_WIDTH;
	}
}

void		set_precision_or_fieldwith(t_data *datas, const int value)
{
	if (value < 0)
	{
		set_precision_or_fieldwith_int(datas, -value, -1);
		prepare_flag_less(datas);
	}
	else
		set_precision_or_fieldwith_int(datas, value, 0);
}
