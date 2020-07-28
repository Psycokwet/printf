/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_one_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/28 09:26:24 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_one_space_int(t_data *datas)
{
    static char c;

    c = ' ';
    if(!(datas->active_flags & FT_PF_FLAG_PRECISION) || (datas->active_flags & FT_PF_FLAG_PRECISION && datas->precision >= 0))
        set_field_width(datas, datas->field_width - 1, "write_one_space");
    return (write(datas->fd, &c, 1));
}

int write_one_space(t_data *datas)
{
    if(datas->value_i >= 0)
        return write_one_space_int(datas);
    return EXIT_SUCCESS;
}
