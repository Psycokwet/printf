/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/21 21:47:53 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#ifndef LINUX

int    write_p(t_data *datas)
{
    printf("HIdden\n");
    fflush(stdout);
    return write_nbr_buffer(datas);
}

#else

int    write_p(t_data *datas)
{
    if (datas->value_p)
        return write_nbr_buffer(datas);
    return write_s(datas);
}

#endif

