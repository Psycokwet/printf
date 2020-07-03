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

    //printf("SET_VALUE\n");
    i = MAX_FLAG_OPT;
    while (--i >= 0){
        if ((value = ft_atoi(code))){
            len = strlen_from_int(value);
            set_precision_or_fieldwith(datas, value);
            //printf("Found VALUE namely :[%d][%d]\n", value, len);
            datas->cursor += len;
            //printf("Found flag namely :%s[%ld][%d]\n", FLAGS[i].code.str, FLAGS[i].code.size, datas->cursor);
            return (EXIT_CODE_FOUND);
        }
    }
    //printf("SET_VALUE OUT\n");
    return (EXIT_CODE_NOT_FOUND);
}
