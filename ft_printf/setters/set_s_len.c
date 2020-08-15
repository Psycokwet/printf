/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 20:05:18 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_s_len(t_data *datas)
{
	datas->len = ft_strlen(datas->value_s);
	if (datas->active_flags & FT_PF_NEG_PRECISION
		&& datas->active_flags & FT_PF_FLAG_PRECISION)
		datas->active_flags -= FT_PF_FLAG_PRECISION;
	if (datas->active_flags & FT_PF_FLAG_PRECISION)
	{
		if (datas->len > (size_t)datas->precision)
			datas->len = datas->precision;
		else
		{
			datas->field_width -= datas->len;
			datas->precision = 0;
		}
		if (datas->field_width > datas->precision)
			datas->field_width -= datas->precision;
		else
			datas->field_width = 0;
	}
	else
	{
		if (datas->active_flags & FT_PF_NEG_PRECISION
		&& datas->unauthorized_flags & FT_PF_FLAG_PRECISION
		&& !(datas->active_flags & FT_PF_WC_PRECISION))
			datas->len = 0;
		datas->field_width -= datas->len;
	}
	if (datas->field_width < 0)
		datas->field_width = 0;
}
