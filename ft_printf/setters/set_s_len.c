/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/07 16:57:32 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void set_s_len(t_data *datas)
{
    datas->len = ft_strlen(datas->value_s);
    //printf(" W :[%d] P:[%d] L: [%ld]\n",  datas->field_width, datas->precision, datas->len);
    if (datas->active_flags & FT_PF_FLAG_PRECISION)
    {
        if (datas->len > (size_t)datas->precision)
            datas->len = datas->precision;
        else{
    set_precision(datas, 0, "set_s_len");

            // datas->precision = 0;
        }
        if (datas->field_width > datas->precision)
            datas->field_width -= datas->precision;
        else
            datas->field_width = 0;
    }
}
