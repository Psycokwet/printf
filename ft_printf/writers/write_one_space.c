/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_one_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/27 19:44:41 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_one_space(t_data *datas)
{
    static char c;

    c = ' ';
    return (write(datas->fd, &c, 1));
}
