/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_padding_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/21 21:50:35 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_padding_d(t_data *datas)
{
    return (write_padding(datas, ' ', datas->field_width));
}
