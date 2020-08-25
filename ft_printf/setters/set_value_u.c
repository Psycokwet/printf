/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/25 16:19:51 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_value_ui(t_data *datas)
{
	if (datas->active_flags & FT_PF_FLAG_H)
		datas->value_u = (unsigned short int)(va_arg(datas->list,
		unsigned int));
	else if (datas->active_flags & FT_PF_FLAG_HH)
		datas->value_u = (unsigned char)(va_arg(datas->list, unsigned int));
	else if (datas->active_flags & FT_PF_FLAG_L)
		datas->value_u = va_arg(datas->list, unsigned long int);
	else if (datas->active_flags & FT_PF_FLAG_LL)
		datas->value_u = va_arg(datas->list, unsigned long long int);
	else
		datas->value_u = va_arg(datas->list, unsigned int);
}
