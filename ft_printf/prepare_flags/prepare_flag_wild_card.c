/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_wild_card.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/07 12:48:46 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void prepare_flag_wild_card(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    if (datas->active_flags & FT_PF_FLAG_PRECISION && value < 0){
        if (datas->active_flags & FT_PF_FLAG_ZERO)
        {
            datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
            datas->precision = datas->field_width;
        }
        else
        {
            datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
            datas->precision = 1;
        }
        //printf("PREPARE WILDCARD\n");
    }
    
    else
        set_precision_or_fieldwith(datas, value);
}
