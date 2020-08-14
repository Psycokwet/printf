/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_undefined.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/07 16:06:11 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

#ifndef LINUX

int set_undefined(const char *code, t_data *datas){
    (void)code;
    (void)datas;
    return (EXIT_CODE_END_FOUND);
}

#else

int set_undefined(const char *code, t_data *datas){
    (void)code;
    int ret = convert_percent(datas);
    if (ret < EXIT_SUCCESS)
        return (-EXIT_FAILURE);
    datas->cursor = datas->last_percent_found;
    return (EXIT_CODE_END_FOUND);
}

#endif
