/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 19:51:11 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

int set_convert(const char *code, t_data *datas){
    int i = MAX_CONVERT_OPT;
    //printf("SET_CONVERT\n");
    while(--i >= 0){
        if(ft_strncmp(CONVERTS[i].code.str, code, CONVERTS[i].code.size) == 0){
            datas->cursor += CONVERTS[i].code.size;
            //printf("Found convert :[%d][%d][%ud]\n", datas->precision, datas->field_width, datas->active_flags);
            return CONVERTS[i].print(datas);
        }
    }
    return EXIT_CODE_NOT_FOUND;
}
