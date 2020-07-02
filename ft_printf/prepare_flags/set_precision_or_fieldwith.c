/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_or_fieldwith.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 19:46:44 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
