/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/14 11:02:24 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    prepare_flag_less(t_data *datas)
{
    if (datas->active_flags & FT_PF_FLAG_PRECISION)
    {
        datas->active_flags -= FT_PF_FLAG_PRECISION;
        datas->unauthorized_flags |= FT_PF_FLAG_PRECISION;
        datas->active_flags |= FT_PF_NEG_PRECISION;
        datas->precision = 0;
    }
    datas->active_flags |= FT_PF_FLAG_LESS;
}
