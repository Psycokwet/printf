/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/24 14:04:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void set_s_len(t_data *datas)
{
    datas->len = ft_strlen(datas->value_s);
   // printf("\nIN  W :[%d] P:[%d] L: [%ld]\n",  datas->field_width, datas->precision, datas->len);
    if(datas->active_flags & FT_PF_NEG_PRECISION && datas->active_flags & FT_PF_FLAG_PRECISION)
        datas->active_flags -= FT_PF_FLAG_PRECISION;
    if (datas->active_flags & FT_PF_FLAG_PRECISION)
    {
        if (datas->len > (size_t)datas->precision)
            datas->len = datas->precision;
        else
        {
            // datas->field_width -= datas->len;
            set_field_width(datas, datas->field_width - datas->len, "set_s_len1");
            set_precision(datas, 0, "set_s_len");
            // datas->precision = 0;
        }
        if (datas->field_width > datas->precision)
            set_field_width(datas, datas->field_width - datas->precision, "set_s_len2");
            // datas->field_width -= datas->precision;
        else
        {
            //datas->field_width = 0;
            set_field_width(datas, 0, "set_s_len3");
        }
    }
    else
    {
        set_field_width(datas, datas->field_width - datas->len, "set_s_len3");
        if (datas->active_flags & FT_PF_NEG_PRECISION && datas->unauthorized_flags & FT_PF_FLAG_PRECISION)
            datas->len = 0;
        // datas->field_width -= datas->len;
    }
    if (datas->field_width < 0)
        set_field_width(datas, 0, "set_s_len4");
        // datas->field_width = 0;
    //printf("OUT W :[%d] P:[%d] L: [%ld]\n",  datas->field_width, datas->precision, datas->len);
}
