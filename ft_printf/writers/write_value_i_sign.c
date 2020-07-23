/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_value_i_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/23 22:47:20 by scarboni         ###   ########.fr       */
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
    set_precision(datas, datas->precision - 1, "write_value_i_sign1");
    if(datas->precision <0)
        set_precision(datas, 0, "write_value_i_sign2");
    return (write(datas->fd, &sign, 1));
}
