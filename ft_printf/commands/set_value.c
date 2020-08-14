/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 20:01:29 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

int set_value(const char *code, t_data *datas){
    int i;
    int value;
    int len;

    i = MAX_FLAG_OPT;
    while (--i >= 0){
        if ((value = ft_atoi(code))){
            len = strlen_from_int(value);
            set_precision_or_fieldwith(datas, value);
            datas->cursor += len;
            return (EXIT_CODE_FOUND);
        }
    }
    return (EXIT_CODE_NOT_FOUND);
}
