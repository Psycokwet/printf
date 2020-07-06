/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/06 08:57:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


static void set_width_precision_d(t_data *datas)
{
    if ((datas->active_flags & FT_PF_FLAG_FIELD_WIDTH && datas->active_flags & FT_PF_FLAG_ZERO) && datas->precision < datas->field_width)
    {
        if (!(datas->active_flags & FT_PF_FLAG_LESS))
        {
            if (!(datas->active_flags & FT_PF_FLAG_PRECISION))
            {
                datas->active_flags |= FT_PF_FLAG_PRECISION;
                datas->precision = datas->field_width;
            }
        }
    }
    datas->precision -= datas->len;
    if (datas->precision < 0)
        datas->precision = 0;

    if (datas->field_width < datas->precision)
        datas->field_width = 0;
        
    datas->field_width -= (datas->len + datas->precision);
    if (datas->field_width < 0)
        datas->field_width = 0;

}

int write_d_in_buffer(t_data *datas)
{

    int len;
	if (datas->value_i < 0)
    {
        datas->active_flags |= FT_PF_FLAG_PLUS;
        len = (ft_uitoa_ext_buffer(-datas->value_i, datas->nbr_buffer, 10, 0));
    }
    else
        len = (ft_uitoa_ext_buffer(datas->value_i, datas->nbr_buffer, 10, 0));
    if (len <= EXIT_SUCCESS)
        return (-EXIT_FAILURE);
    datas->len = (size_t)len;   
    set_width_precision_d(datas);
    return (EXIT_SUCCESS);
}

    //printf("\nDATAS : W%d  L%d  P%d  SIDE%d\n", datas->field_width, len, datas->precision, datas->active_flags & FT_PF_FLAG_LESS);
/*
    if (datas->active_flags & FT_PF_FLAG_FIELD_WIDTH && datas->active_flags & FT_PF_FLAG_ZERO)
    {
        if(datas->active_flags & FT_PF_FLAG_PRECISION && !(datas->precision > datas->field_width))
        {
            datas->precision = datas->field_width;
            datas->active_flags -= FT_PF_FLAG_FIELD_WIDTH;
        }else
        {
            datas->active_flags |= FT_PF_FLAG_PRECISION;
            datas->precision = datas->field_width;
            datas->active_flags -= FT_PF_FLAG_FIELD_WIDTH;
        }
    }
    //printf("\nDATAS : W%d  L%d  P%d  SIDE%d\n", datas->field_width, len, datas->precision, datas->active_flags & FT_PF_FLAG_LESS);

    if ((datas->active_flags & FT_PF_FLAG_FIELD_WIDTH && datas->active_flags & FT_PF_FLAG_PRECISION))
    {
        if(datas->precision > datas->field_width)
        {
            datas->active_flags |= FT_PF_FLAG_PRECISION;
            datas->active_flags -= FT_PF_FLAG_FIELD_WIDTH;
        }
        /else
            if(datas->precision > len)
            {
                datas->precision -= len;
            }
    }
   // printf("\nDATAS : W%d  L%d  P%d  SIDE%d\n", datas->field_width, len, datas->precision, datas->active_flags & FT_PF_FLAG_LESS);


   // printf("\nDATASOUT : W%d  L%d  P%d  SIDE%d\n", datas->field_width, len, datas->precision, datas->active_flags & FT_PF_FLAG_LESS);
*/
