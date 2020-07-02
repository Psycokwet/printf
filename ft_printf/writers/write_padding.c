/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 19:34:12 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_padding(t_data *datas)
{
    int ret_read;
    int padding_count;
    //printf("write_padding W :[%d] P:[%d]\n",  datas->field_width, datas->precision);
    padding_count = 0;
    while (padding_count < datas->field_width)
    {
        ret_read = write(datas->fd, &(datas->padding_c), 1);
        padding_count += ret_read;
        if (ret_read < 0 )
            return (-EXIT_FAILURE);
    }
    if (padding_count < 0 || padding_count != datas->field_width)
        return (-EXIT_FAILURE);
    return (padding_count);
}
