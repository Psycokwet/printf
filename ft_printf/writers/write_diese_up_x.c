/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_diese_up_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 08:06:59 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_diese_up_x(t_data *datas)
{
    char *diese = "0X";
    return (write_str(datas->fd, diese, 2));
}
