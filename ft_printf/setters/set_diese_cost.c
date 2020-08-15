/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_diese_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 20:05:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_diese_cost(t_data *datas)
{
	if (datas->active_flags & FT_PF_FLAG_DIESE
		&& !(datas->unauthorized_flags & FT_PF_FLAG_DIESE))
	{
		datas->field_width -= 2;
		if (datas->field_width < 0)
			datas->field_width = 0;
	}
}
