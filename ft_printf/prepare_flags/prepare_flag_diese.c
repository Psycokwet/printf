/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_flag_diese.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:26:48 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/22 17:30:09 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
//valide conversion :"diouxXaAeEfFgG"
void prepare_flag_diese(t_data *datas)
{
    datas->active_flags |= FT_PF_FLAG_DIESE;
}
