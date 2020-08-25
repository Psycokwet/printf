/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/25 15:59:10 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_value_d(t_data *datas)
{
	if(datas->active_flags & FT_PF_FLAG_H)
		datas->value_i = (short int)(va_arg(datas->list, int));
	else if(datas->active_flags & FT_PF_FLAG_HH)
		datas->value_i = (char)(va_arg(datas->list, int));
	else if(datas->active_flags & FT_PF_FLAG_L)
		datas->value_i = va_arg(datas->list, long int);
	else if(datas->active_flags & FT_PF_FLAG_LL)
		datas->value_i = va_arg(datas->list, long long int);
	else
		datas->value_i = va_arg(datas->list, int);
}
