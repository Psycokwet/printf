/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_padding_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 10:20:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_padding_s(t_data *datas)
{
	return (write_padding(datas, datas->padding_c, datas->field_width));
}
