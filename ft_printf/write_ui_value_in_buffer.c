/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ui_value_in_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 09:06:59 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_ui_value_in_buffer(t_data *datas, unsigned int value)
{
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 16, 'a');
    if (len <= EXIT_SUCCESS)
        return (-EXIT_FAILURE);
    datas->len = (size_t)len;
    return (EXIT_SUCCESS);
}
