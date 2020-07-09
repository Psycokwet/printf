/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/08 19:31:06 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
//left padding
//override a given 0
void prepare_flag_less(t_data *datas)
{
    if (datas->active_flags & FT_PF_FLAG_PRECISION)
    {
        datas->active_flags -= FT_PF_FLAG_PRECISION;
        datas->precision = 0;
    }
    datas->active_flags |= FT_PF_FLAG_LESS;
}
