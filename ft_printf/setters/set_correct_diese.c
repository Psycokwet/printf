/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_correct_diese.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/22 16:01:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void set_correct_diese(t_data *datas)
{
    if(datas->value_ui == 0 && datas->active_flags & FT_PF_FLAG_DIESE){
        datas->unauthorized_flags |= FT_PF_FLAG_DIESE;
        //datas->active_flags -= FT_PF_FLAG_DIESE;
    }
    if(datas->active_flags & FT_PF_FLAG_DIESE && !(datas->unauthorized_flags & FT_PF_FLAG_DIESE))
    {
        // datas->field_width -= 2;
        set_field_width(datas, datas->field_width - 2, "set_correct_diese1");
        if(datas->field_width < 0)
            set_field_width(datas, 0, "set_correct_diese2");
            // datas->field_width = 0;
        //set_precision(datas, datas->precision + datas->field_width, "set_correct_diese");
        // datas->precision += datas->field_width;
    }
    
}
