/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_precision_u_x_up_x.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:44:25 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/21 21:08:18 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void set_width_precision_u_x_up_x(t_data *datas)
{
    if(datas->value_ui == 0 && datas->precision == 0)
        datas->len = 0;
    if((size_t)datas->precision > datas->len)
        datas->precision -= datas->len;
    else
        datas->precision = 0;
    datas->field_width -= datas->len + datas->precision;
    if(datas->active_flags & FT_PF_NEG_PRECISION && datas->active_flags & FT_PF_FLAG_FIELD_WIDTH ){
        datas->precision = datas->field_width;
        datas->active_flags -= FT_PF_FLAG_FIELD_WIDTH;
        datas->active_flags |= FT_PF_FLAG_PRECISION;
    }
}
