/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_value_i_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/23 22:56:54 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int    write_value_i_sign(t_data *datas)
{
    int sign;

    if(datas->value_i < 0)
        sign = '-';
    else
        sign = '+';
    return (write(datas->fd, &sign, 1));
}
