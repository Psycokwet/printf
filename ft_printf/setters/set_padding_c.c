/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_padding_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 20:04:42 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_padding_c(t_data *datas)
{
	if (datas->active_flags & FT_PF_FLAG_ZERO
		&& !(datas->active_flags & FT_PF_FLAG_LESS))
		datas->padding_c = '0';
	else
		datas->padding_c = ' ';
}
