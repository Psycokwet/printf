/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_wild_card.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/08 18:55:09 by scarboni         ###   ########.fr       */
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
                //datas->precision = datas->field_width;
                set_precision(datas, 1, "prepare_flag_wild_card 1");
            }
            else
            {
                //datas->precision = datas->field_width;
                if (datas->field_width == 0)
                    set_precision(datas, 1, "prepare_flag_wild_card 2");
                else
                {
                    set_precision(datas, datas->field_width, "prepare_flag_wild_card 2");
                    datas->active_flags |= FT_PF_NEG_PRECISION;
                }
            }
            datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
        }
        else
        {
            datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
            set_precision(datas, 1, "prepare_flag_wild_card 3");
            //datas->precision = 1;
        }
        //printf("PREPARE WILDCARD\n");
    }
    else
        set_precision_or_fieldwith(datas, value);
}
