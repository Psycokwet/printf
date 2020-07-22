/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_precision_x_up_x.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:44:25 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/22 17:28:57 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void set_width_precision_x_up_x(t_data *datas)
{
    //printf("prevW:%d::P:%d::L:%zu::V%d::NEG%d\n", datas->field_width, datas->precision, datas->len, datas->value_ui, (datas->active_flags & FT_PF_NEG_PRECISION)?1:0);
    if(datas->value_ui == 0 && datas->precision <= 0 && !(datas->active_flags & FT_PF_NEG_PRECISION))
        datas->len = 0;
    if((size_t)datas->precision > datas->len)
        set_precision(datas, datas->precision - datas->len, "set_width_precision_x_up_x1");
        // datas->precision -= datas->len;
    else
        set_precision(datas, 0, "set_width_precision_x_up_x2");
        //datas->precision = 0;
    set_field_width(datas, datas->field_width - (datas->len + datas->precision), "set_width_precision_x_up_x");
    // datas->field_width -= datas->len + datas->precision;
    
    if((datas->active_flags & FT_PF_NEG_PRECISION 
            && datas->active_flags & FT_PF_FLAG_FIELD_WIDTH 
            && datas->active_flags & FT_PF_NEG_FIELD_WIDTH 
            && datas->active_flags & FT_PF_FLAG_ZERO 
            //&& !(datas->active_flags & FT_PF_FLAG_DIESE) 
            && !(datas->active_flags & FT_PF_FLAG_LESS)
        ) || (
            datas->active_flags & FT_PF_NEG_PRECISION 
            && !(datas->active_flags & FT_PF_NEG_FIELD_WIDTH )
            && !(datas->active_flags & FT_PF_FLAG_LESS)
            && datas->unauthorized_flags & FT_PF_FLAG_DIESE
            && datas->active_flags & FT_PF_FLAG_ZERO 
        ) || (
            datas->active_flags & FT_PF_NEG_PRECISION 
            && !(datas->active_flags & FT_PF_NEG_FIELD_WIDTH )
            && !(datas->active_flags & FT_PF_FLAG_LESS)
            && datas->active_flags & FT_PF_FLAG_DIESE
            && datas->active_flags & FT_PF_FLAG_ZERO 
        )
    ){
        set_precision(datas, datas->field_width, "set_width_precision_x_up_x3");
        //datas->precision = datas->field_width;
        datas->active_flags -= FT_PF_FLAG_FIELD_WIDTH;
        datas->active_flags |= FT_PF_FLAG_PRECISION;
    }
    // printf("after NEGP:%d::NEGW:%d::LESS:%d::DIESE:%d::ZERO:%d::\n", datas->active_flags & FT_PF_NEG_PRECISION ? 1:0,
    //         !(datas->active_flags & FT_PF_NEG_FIELD_WIDTH ) ? 1:0,
    //          !(datas->active_flags & FT_PF_FLAG_LESS) ? 1:0,
    //          datas->unauthorized_flags & FT_PF_FLAG_DIESE ? 1:0,
    //          datas->active_flags & FT_PF_FLAG_ZERO  ? 1:0);
}
