/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/06 10:24:25 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


static void set_width_precision_d(t_data *datas, int full_len)
{
    if ((datas->active_flags & FT_PF_FLAG_FIELD_WIDTH && datas->active_flags & FT_PF_FLAG_ZERO) && datas->precision < datas->field_width)
    {
        if (!(datas->active_flags & FT_PF_FLAG_LESS))
        {
            if (!(datas->active_flags & FT_PF_FLAG_PRECISION))
            {
                datas->active_flags |= FT_PF_FLAG_PRECISION;
                datas->precision = datas->field_width;
            }
        }
    }
    datas->precision -= full_len;
    if (datas->precision < 0)
        datas->precision = 0;
    if (datas->field_width < datas->precision)
        datas->field_width = 0;
    datas->field_width -= (full_len + datas->precision);
    if (datas->field_width < 0)
        datas->field_width = 0;
}

int write_d_in_buffer(t_data *datas)
{
    int full_len;
    int len;
    
	if (datas->value_i < 0)
    {
        datas->active_flags |= FT_PF_FLAG_PLUS;
        len = (ft_uitoa_ext_buffer(-datas->value_i, datas->nbr_buffer, 10, 0));
        full_len = len + 1;
    }
    else
    {
        len = (ft_uitoa_ext_buffer(datas->value_i, datas->nbr_buffer, 10, 0));
        full_len = len;
    }
    if (len <= EXIT_SUCCESS)
        return (-EXIT_FAILURE);
    datas->len = (size_t)len;   
    set_width_precision_d(datas, full_len);
    return (EXIT_SUCCESS);
}
