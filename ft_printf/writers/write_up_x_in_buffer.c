/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_up_x_in_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 10:20:37 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_up_x_in_buffer(t_data *datas)
{
	return (write_uix_value_in_buffer(datas, 16, 'A'));
}
