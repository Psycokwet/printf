/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_wild_card.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/22 10:08:42 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void prepare_flag_wild_card(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    if (datas->active_flags & FT_PF_FLAG_PRECISION && value < 0){
        if (datas->active_flags & FT_PF_FLAG_ZERO)
        {
            if (datas->active_flags & FT_PF_FLAG_LESS)
            {
                //datas->precision = 1;
                set_precision(datas, 1, "prepare_flag_wild_card1");
            }
            else
            {
                if (datas->field_width == 0)
                    set_precision(datas, 1, "prepare_flag_wild_card2");
                    //datas->precision = 1;
                else
                    set_precision(datas, datas->field_width, "prepare_flag_wild_card3");
                    // datas->precision = datas->field_width;
            }
            datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
        }
        else
        {
            datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
            set_precision(datas, 1, "prepare_flag_wild_card4");
            //datas->precision = 1;
        }
        datas->active_flags |= FT_PF_NEG_PRECISION;
    }
    else
        set_precision_or_fieldwith(datas, value);
    //printf("NEG PRECISION ? %d:%d\n", datas->active_flags & FT_PF_NEG_PRECISION, value);
}
