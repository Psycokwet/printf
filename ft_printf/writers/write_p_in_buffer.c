/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p_in_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 18:29:22 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#ifndef LINUX

int write_p_in_buffer(t_data *datas)
{
    return (write_ui_value_in_buffer(datas, (unsigned int)datas->value_p));
}

#else

int write_p_in_buffer(t_data *datas)
{
    if(datas->value_p)
        return (write_ui_value_in_buffer(datas, (unsigned int)datas->value_p));
    return (EXIT_SUCCESS);
}

#endif

