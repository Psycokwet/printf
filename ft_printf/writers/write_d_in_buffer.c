/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 14:22:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	flatten_value(int value)
{
	if (value < 0)
		return (0);
	else
		return (value);
}

static void	set_width_precision_d_int(t_data *datas, int sign)
{
	if (datas->value_i == 0 && datas->precision == 0)
		datas->len = 0;
	if (
			(datas->active_flags & FT_PF_FLAG_FIELD_WIDTH
			&& datas->active_flags & FT_PF_FLAG_ZERO)
		&& datas->precision < datas->field_width
		&& (!(datas->active_flags & FT_PF_FLAG_LESS))
		&& (!(datas->active_flags & FT_PF_FLAG_PRECISION)))
	{
		datas->active_flags |= FT_PF_FLAG_PRECISION;
		datas->precision = datas->field_width -
		((datas->active_flags & FT_PF_FLAG_PLUS || sign < 0) ? 1 : 0);
	}
}

static void	set_width_precision_d(t_data *datas, int sign)
{
	int precision_tmp;

	set_width_precision_d_int(datas, sign);
	precision_tmp = 0;
	if (datas->active_flags & FT_PF_FLAG_PRECISION)
	{
		datas->precision = flatten_value(datas->precision - datas->len);
		precision_tmp = datas->precision;
	}
	if ((datas->active_flags & FT_PF_FLAG_PRECISION)
		&& datas->field_width < precision_tmp)
		datas->field_width = 0;
	datas->field_width =
	flatten_value(datas->field_width - (datas->len + (-sign) + precision_tmp));
	if (datas->active_flags & FT_PF_NEG_PRECISION
		&& datas->active_flags & FT_PF_FLAG_PLUS)
		datas->precision = flatten_value(datas->precision - 1);
	if (datas->active_flags & FT_PF_FLAG_PLUS && sign == 0)
		datas->field_width = flatten_value(datas->field_width - 1);
}

int			write_d_in_buffer(t_data *datas)
{
	int sign;
	int len;

	if (datas->value_i < 0)
	{
		datas->active_flags |= FT_PF_FLAG_PLUS;
		len = (ft_uitoa_ext_buffer(-datas->value_i, datas->nbr_buffer, 10, 0));
		sign = -1;
	}
	else
	{
		len = (ft_uitoa_ext_buffer(datas->value_i, datas->nbr_buffer, 10, 0));
		sign = 0;
	}
	if (len <= EXIT_SUCCESS)
		return (-EXIT_FAILURE);
	datas->len = (size_t)len;
	set_width_precision_d(datas, sign);
	return (EXIT_SUCCESS);
}
