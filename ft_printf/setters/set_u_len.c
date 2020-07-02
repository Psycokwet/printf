/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_u_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 18:15:22 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int set_u_len(t_data *datas)
{
    const int len = ft_uitoa_ext_buffer(datas->value_ui, datas->nbr_buffer, 10, 0);
    if (len <= EXIT_SUCCESS)
        return (-EXIT_FAILURE);
    datas->len = (size_t)len;
    return (EXIT_SUCCESS);
}
