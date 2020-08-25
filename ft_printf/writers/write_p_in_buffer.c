/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/25 10:12:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#ifndef LINUX

int	write_p_in_buffer(t_data *datas)
{
	datas->value_u = (unsigned long)datas->value_p;
	return (write_x_in_buffer(datas));
}

#else

int	write_p_in_buffer(t_data *datas)
{
	datas->value_u = (unsigned long)datas->value_p;
	if (datas->value_p)
		return (write_x_in_buffer(datas));
	return (EXIT_SUCCESS);
}

#endif
