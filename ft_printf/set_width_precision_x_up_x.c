/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_precision_x_up_x.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:44:25 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/22 10:07:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void set_width_precision_x_up_x(t_data *datas)
{
    printf("prevW:%d::P:%d::L:%zu\n", datas->field_width, datas->precision, datas->len);
    if(datas->value_ui == 0 && datas->precision == 0)
        datas->len = 0;
    if((size_t)datas->precision > datas->len)
        datas->precision -= datas->len;
    else
        set_precision(datas, 0, "set_width_precision_x_up_x");
        //datas->precision = 0;
    datas->field_width -= datas->len + datas->precision;
    // if(datas->active_flags & FT_PF_NEG_PRECISION 
    //     && datas->active_flags & FT_PF_FLAG_FIELD_WIDTH 
    //     && !(datas->active_flags & FT_PF_FLAG_DIESE) 
    //     && !(datas->active_flags & FT_PF_FLAG_LESS)){
    //     datas->precision = datas->field_width;
    //     datas->active_flags -= FT_PF_FLAG_FIELD_WIDTH;
    //     datas->active_flags |= FT_PF_FLAG_PRECISION;
    // }
    printf("afterW:%d::P:%d::L:%zu\n", datas->field_width, datas->precision, datas->len);
}
