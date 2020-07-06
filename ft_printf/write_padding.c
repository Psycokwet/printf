/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/05 18:06:49 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_padding(t_data *datas, const int padding_c, const int padding_max)
{
    int ret_read;
    int padding_count;

    padding_count = 0;
    while (padding_count < padding_max)
    {
        ret_read = write(datas->fd, &(padding_c), 1);
        padding_count += ret_read;
        if (ret_read < 0 )
            return (-EXIT_FAILURE);
    }
    return (padding_count);
}
