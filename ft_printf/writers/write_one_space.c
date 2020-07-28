/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_one_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/28 11:23:19 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_one_space_int(t_data *datas)
{
    static char c;

    c = ' ';
    printf(" %d:%d\n", datas->active_flags & FT_PF_FLAG_ZERO ?1:0,datas->active_flags & FT_PF_NEG_PRECISION?1:0);
    if(     
            (!(datas->active_flags & FT_PF_FLAG_PRECISION) 
            || (datas->active_flags & FT_PF_FLAG_PRECISION 
            && datas->precision >= 0))
        ||
            (datas->active_flags & FT_PF_FLAG_ZERO
            && datas->active_flags & FT_PF_NEG_PRECISION)
        )
        set_field_width(datas, datas->field_width - 1, "write_one_space");
    return (write(datas->fd, &c, 1));
}

int write_one_space(t_data *datas)
{
    if(datas->value_i >= 0)
        return write_one_space_int(datas);
    return EXIT_SUCCESS;
}
