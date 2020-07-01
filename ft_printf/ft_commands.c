/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/01 15:28:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int set_undefined(const char *code, t_data *datas){
    printf("\nUNDEFINED BEHAVIOR %s\n", code);
    (void)datas;
    return -EXIT_FAILURE;
}

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

static size_t	strlen_from_int(int value)
{
	size_t result;

	result = 0;
    if(value < 0){
        value = -value;
		result++;
    }
	else if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / 10;
		result++;
	}
	return (result);
}

int set_value(const char *code, t_data *datas){
    int i;
    int value;
    int len;

    //printf("SET_VALUE\n");
    i = MAX_FLAG_OPT;
    while(--i >= 0){
        if((value = ft_atoi(code))){
            len = strlen_from_int(value);
            set_precision_or_fieldwith(datas, value);
            //printf("Found VALUE namely :[%d][%d]\n", value, len);
            datas->cursor += len;
            //printf("Found flag namely :%s[%ld][%d]\n", FLAGS[i].code.str, FLAGS[i].code.size, datas->cursor);
            return EXIT_CODE_FOUND;
        }
    }
    //printf("SET_VALUE OUT\n");
    return EXIT_CODE_NOT_FOUND;
}

int set_flag(const char *code, t_data *datas){
    int i = MAX_FLAG_OPT;
    //printf("SET_FLAG\n");

    //printf("SET_FLAG [%s]\n", code);
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
