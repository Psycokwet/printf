/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_wild_card.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/14 11:04:29 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	prepare_flag_wild_card(t_data *datas)
{
	const int value = va_arg(datas->list, int);

	if (datas->active_flags & FT_PF_FLAG_PRECISION && value < 0)
	{
		if (datas->active_flags & FT_PF_FLAG_ZERO)
		{
			if (datas->active_flags & FT_PF_FLAG_LESS)
				datas->precision = 1;
			else
				if (datas->field_width == 0)
					datas->precision = 1;
				else
					datas->precision = datas->field_width;
			datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
		}
		else
		{
			datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
			datas->precision = 1;
		}
		datas->active_flags |= FT_PF_NEG_PRECISION;
		datas->active_flags |= FT_PF_WC_PRECISION;
	}
	else
		set_precision_or_fieldwith(datas, value);
}
