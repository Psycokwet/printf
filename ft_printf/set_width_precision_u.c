/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_precision_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:44:25 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/24 09:51:06 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void set_width_precision_u(t_data *datas)
{
    if(datas->value_ui == 0 && datas->precision == 0)
        datas->len = 0;
    if((size_t)datas->precision > datas->len)
        set_precision(datas, datas->precision - datas->len, "set_width_precision_u1");
        // datas->precision -= datas->len;
    else
        set_precision(datas, 0, "set_width_precision_u2");
        //datas->precision = 0;
    set_field_width(datas, datas->field_width - (datas->len + datas->precision), "set_width_precision_u");
    if(datas->active_flags & FT_PF_FLAG_ZERO && datas->active_flags & FT_PF_FLAG_FIELD_WIDTH && !(datas->active_flags & FT_PF_FLAG_PRECISION))
    {
        datas->active_flags -= FT_PF_FLAG_FIELD_WIDTH;
        datas->active_flags |= FT_PF_FLAG_PRECISION;
        set_precision(datas, datas->field_width, "set_width_precision_u3");
    }
    // datas->field_width -= datas->len + datas->precision;
}
