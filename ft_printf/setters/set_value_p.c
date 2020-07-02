/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 18:14:08 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void set_value_p(t_data *datas)
{
    datas->value_p  = va_arg(datas->list, char*);
    if (datas->value_p){
        printf("NEED IMPLEMENTATION\n");
        return;
    }
    datas->value_s = "(nil)";
    datas->len = ft_strlen(datas->value_s);
}
