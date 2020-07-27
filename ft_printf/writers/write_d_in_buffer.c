/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/27 14:15:07 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


static void set_width_precision_d(t_data *datas, int sign)
{
    if(datas->value_i == 0 && datas->precision == 0)
        datas->len = 0;

    int precision_tmp;
    //printf("DATAS  W:%d L:%zu P:%d\n", datas->field_width, datas->len, datas->precision);
    if ((datas->active_flags & FT_PF_FLAG_FIELD_WIDTH && datas->active_flags & FT_PF_FLAG_ZERO) && datas->precision < datas->field_width)
    {
        if (!(datas->active_flags & FT_PF_FLAG_LESS))
        {
            if (!(datas->active_flags & FT_PF_FLAG_PRECISION))
            {
                datas->active_flags |= FT_PF_FLAG_PRECISION;
                // datas->precision = datas->field_width -(-sign);
                if(datas->active_flags & FT_PF_FLAG_PLUS || sign < 0)
                    set_precision(datas, datas->field_width - 1, "set_width_precision_d0");
                else
                    set_precision(datas, datas->field_width, "set_width_precision_d01");

            }
        }
    }
    //printf("DATAS MID  W:%d L:%zu P:%d\n", datas->field_width, datas->len, datas->precision);
    precision_tmp = 0;
    if (datas->active_flags & FT_PF_FLAG_PRECISION)
    {
        //printf("HEYOU\n");
        set_precision(datas, datas->precision - datas->len, "set_width_precision_d1");
        // datas->precision -= datas->len;
        if (datas->precision < 0){
            set_precision(datas, 0, "set_width_precision_d2");
            // datas->precision = 0;
        }
        precision_tmp = datas->precision;
    }
    if ((datas->active_flags & FT_PF_FLAG_PRECISION) && datas->field_width < precision_tmp)
        set_field_width(datas, 0, "set_width_precision_d1");
        // datas->field_width = 0;
    set_field_width(datas, datas->field_width - (datas->len + (-sign) + precision_tmp), "set_width_precision_d13");
    // datas->field_width -= (datas->len + (-sign) + precision_tmp);
    if (datas->field_width < 0)
        set_field_width(datas, 0, "set_width_precision_d2");
        // datas->field_width = 0;
    if(datas->active_flags & FT_PF_NEG_PRECISION && datas->active_flags & FT_PF_FLAG_PLUS)
        set_precision(datas,  datas->precision-1, "set_width_precision_d3");
        // datas->precision--;
    if (datas->precision < 0)
        set_precision(datas, 0, "set_width_precision_d4");
        //datas->precision = 0;

    if(datas->active_flags & FT_PF_FLAG_PLUS && sign == 0)
    {
        // datas->field_width--;
        set_field_width(datas, datas->field_width-1, "set_width_precision_d4");
        if (datas->field_width < 0)
            set_field_width(datas, 0, "set_width_precision_d5");
            // datas->field_width = 0;
    }
    //printf("DATAS END W:%d L:%zu P:%d\n", datas->field_width, datas->len, datas->precision);
}

int write_d_in_buffer(t_data *datas)
{
    printf("write_d_in_buffer %d\n", datas->field_width);
    fflush(stdout);
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
