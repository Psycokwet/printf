/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_precision_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/05 18:45:47 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_precision_d(t_data *datas)
{
    return (write_padding(datas, '0', datas->precision));
}
