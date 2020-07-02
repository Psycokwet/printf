/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 18:10:23 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int    write_s(t_data *datas)
{
    int ret_read;
    //printf("WRITE\n");
    ret_read = write(datas->fd, datas->value_s, datas->len);
    if (ret_read < 0 || (size_t)ret_read != datas->len)
        return (-EXIT_FAILURE);
    return (ret_read);
}
