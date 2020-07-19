/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_diese_x_up_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/19 11:05:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_diese_x_up_x(t_data *datas, char *diese)
{
    datas->field_width -= 2;
    if(datas->field_width < 0)
        datas->field_width = 0;
    return (write_str(datas->fd, diese, 2));
}
