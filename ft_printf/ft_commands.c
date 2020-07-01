/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/01 12:03:06 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int set_undefined(const char *code, t_data *datas){
    printf("\nUNDEFINED BEHAVIOR %s\n", code);
    (void)datas;
    return -EXIT_FAILURE;
}

int set_flag(const char *code, t_data *datas){
    int i = MAX_FLAG_OPT;
    //printf("SET_FLAG\n");

    while(--i >= 0){
        if(ft_strncmp(FLAGS[i].code.str, code, FLAGS[i].code.size) == 0){
            //printf("Found flag namely :%s[%ld][%d]\n", FLAGS[i].code.str, FLAGS[i].code.size, datas->cursor);
            datas->cursor += FLAGS[i].code.size;
            //printf("Found flag namely :%s[%ld][%d]\n", FLAGS[i].code.str, FLAGS[i].code.size, datas->cursor);
            FLAGS[i].prepare_flag(datas);
            return EXIT_CODE_FOUND;
        }
    }
    return EXIT_CODE_NOT_FOUND;
}

int set_convert(const char *code, t_data *datas){
    int i = MAX_CONVERT_OPT;
    //printf("SET_CONVERT\n");
    while(--i >= 0){
        if(ft_strncmp(CONVERTS[i].code.str, code, CONVERTS[i].code.size) == 0){
            datas->cursor += CONVERTS[i].code.size;
            //printf("Found convert namely :[%s][%s]\n", CONVERTS[i].code.str, datas->format_s + datas->cursor);
            return CONVERTS[i].print(datas);
        }
    }
    return EXIT_CODE_NOT_FOUND;
}
