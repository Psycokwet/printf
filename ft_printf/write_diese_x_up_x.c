/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_diese_x_up_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/22 16:03:48 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_diese_x_up_x(t_data *datas, char *diese)
{
    if(!(datas->unauthorized_flags & FT_PF_FLAG_DIESE))
        return (write_str(datas->fd, diese, 2));
    return (EXIT_SUCCESS);
}
