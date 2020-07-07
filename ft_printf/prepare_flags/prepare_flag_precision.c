/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/07 10:45:15 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void prepare_flag_precision(t_data *datas)
{
    datas->active_flags |= FT_PF_FLAG_PRECISION;
    datas->precision = 0;
}
