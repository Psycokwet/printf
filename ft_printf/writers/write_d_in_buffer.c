/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/07 12:28:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


static void set_width_precision_d(t_data *datas, int sign)
{
    //printf("DATAS  W:%d L:%zu P:%d\n", datas->field_width, datas->len, datas->precision);
    if ((datas->active_flags & FT_PF_FLAG_FIELD_WIDTH && datas->active_flags & FT_PF_FLAG_ZERO) && datas->precision < datas->field_width)
    {
        if (!(datas->active_flags & FT_PF_FLAG_LESS))
        {
            if (!(datas->active_flags & FT_PF_FLAG_PRECISION))
            {
                datas->active_flags |= FT_PF_FLAG_PRECISION;
                datas->precision = datas->field_width -(-sign);
            }
        }
    }
    //printf("DATAS MID  W:%d L:%zu P:%d\n", datas->field_width, datas->len, datas->precision);
    datas->precision -= datas->len;
    if (datas->precision < 0)
        datas->precision = 0;
    if (datas->field_width < datas->precision)
        datas->field_width = 0;
    datas->field_width -= (datas->len + (-sign) + datas->precision);
    if (datas->field_width < 0)
        datas->field_width = 0;
    //printf("DATAS END W:%d L:%zu P:%d\n", datas->field_width, datas->len, datas->precision);
}

int write_d_in_buffer(t_data *datas)
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
    if(datas->active_flags & FT_PF_FLAG_PRECISION && datas->value_i == 0 && datas->precision == 0)
    {
        //printf("PRECISION %d\n",datas->precision);
        datas->len = 0;
    }
        //printf("PRECISIONELSE  %d %d %d\n",datas->precision , datas->active_flags & FT_PF_FLAG_PRECISION , datas->value_i );
    set_width_precision_d(datas, sign);
    return (EXIT_SUCCESS);
}
