/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/01 20:32:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//left padding
//override a given 0
void prepare_flag_less(t_data *datas)
{
    datas->active_flags |= FT_PF_FLAG_LESS;
}
//valide conversion :"diouxXaAeEfFgG"
void prepare_flag_0(t_data *datas)
{
    datas->active_flags |= FT_PF_FLAG_ZERO;
}

void prepare_flag_precision(t_data *datas)
{
    datas->active_flags |= FT_PF_FLAG_PRECISION;
}

void set_precision_or_fieldwith(t_data *datas, const int value)
{
    if(datas->active_flags & FT_PF_FLAG_PRECISION)
        datas->precision = value;
    else{
        datas->active_flags |= FT_PF_FLAG_FIELD_WIDTH;
        datas->field_width = value;
    }
    if(value < 0)
        prepare_flag_less(datas);
}


void prepare_flag_wild_card(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    set_precision_or_fieldwith(datas, value);
}
