/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 18:18:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#ifndef LINUX

void set_value_p(t_data *datas)
{
    datas->value_p  = va_arg(datas->list, char*);
    if (datas->value_p){
        datas->active_flags |= FT_PF_FLAG_DIESE;
        return;
    }
    datas->value_s = nil;
    datas->len = ft_strlen(datas->value_s);
}

#else

void set_value_p(t_data *datas)
{
    datas->active_flags |= FT_PF_FLAG_DIESE;
    datas->value_p  = va_arg(datas->list, void*);
}

#endif
