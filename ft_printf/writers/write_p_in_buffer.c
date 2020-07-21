/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/21 21:22:19 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#ifndef LINUX

int write_p_in_buffer(t_data *datas)
{
    datas->value_ui = (unsigned int)datas->value_p;
    return (write_uix_value_in_buffer(datas, 16, 'a'));
}

#else

int write_p_in_buffer(t_data *datas)
{
    datas->value_ui = (unsigned int)datas->value_p;
    if(datas->value_p)
        return (write_uix_value_in_buffer(datas, 16, 'a'));
    return (EXIT_SUCCESS);
}

#endif

