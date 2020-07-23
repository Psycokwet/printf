/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/23 20:50:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
//valide conversion :"diouxXaAeEfFgG"
void prepare_flag_0(t_data *datas)
{
    if(!(datas->active_flags & FT_PF_FLAG_PRECISION))
        datas->active_flags |= FT_PF_FLAG_ZERO;
}
