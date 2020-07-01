/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/01 12:03:20 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void prepare_flag_less(t_data *datas)
{
    datas->active_flags &= FT_PF_FLAG_LESS;
}

void prepare_flag_0(t_data *datas)
{
   // printf("AH QUE COUCOU BOB \n");
    (void)datas;
    datas->active_flags &= FT_PF_FLAG_ZERO;
}

void prepare_flag_precision(t_data *datas)
{
    datas->active_flags &= FT_PF_FLAG_PRECISION;
}

void prepare_flag_wild_card(t_data *datas)
{
    const int value  = va_arg(datas->list, int);

    if(datas->active_flags & FT_PF_FLAG_PRECISION)
        datas->precision = value;
    else{
        datas->active_flags &= FT_PF_FLAG_FIELD_WIDTH;
        datas->field_width = value;
    }
}
