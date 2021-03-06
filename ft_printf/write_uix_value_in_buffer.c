/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uix_value_in_buffer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:44:34 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/25 10:12:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_uix_value_in_buffer(t_data *datas, int base, char fauxchiffre)
{
	int len;

	len = ft_uitoa_ext_buffer(datas->value_u, datas->nbr_buffer, base,
		fauxchiffre);
	if (len <= EXIT_SUCCESS)
		return (-EXIT_FAILURE);
	datas->len = (size_t)len;
	set_width_precision_x_up_x(datas);
	return (EXIT_SUCCESS);
}
