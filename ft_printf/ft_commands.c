/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/01 10:26:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int set_undefined(const char *code, t_data *datas){
    printf("\nUNDEFINED BEHAVIOR %s\n", code);
    (void)datas;
    return -1;
}

int set_flag(const char *code, t_data *datas){
    int i = MAX_FLAG_OPT;

    while(--i >= 0){
        if(ft_strncmp(FLAGS[i].code.str, code, FLAGS[i].code.size) == 0){
            datas->cursor += FLAGS[i].code.size;
            //printf("Found flag namely :%s\n", FLAGS[i].code.str);
            FLAGS[i].prepare_flag(datas);
            return 1;
        }
    }
    return 0;
}

int set_convert(const char *code, t_data *datas){
    int i = MAX_CONVERT_OPT;
    while(--i >= 0){
        if(ft_strncmp(CONVERTS[i].code.str, code, CONVERTS[i].code.size) == 0){
            datas->cursor += CONVERTS[i].code.size;
            CONVERTS[i].print(datas);
           // printf("Found convert namely :[%ld][%s]\n", CONVERTS[i].code.size, datas->format_s + datas->cursor);
            return 1;
        }
    }
    return 0;
}
