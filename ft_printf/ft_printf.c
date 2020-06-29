/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/06/26 19:37:27 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void prepare_flag_less(t_data *datas)
{
    datas->active_flags &= FT_PF_FLAG_LESS;
}

void prepare_flag_0(t_data *datas)
{
    datas->active_flags &= FT_PF_FLAG_ZERO;
}

void prepare_flag_precision(t_data *datas)
{
    datas->active_flags &= FT_PF_FLAG_PRECISION;
}

void prepare_flag_wild_card(t_data *datas)
{
    const int value  = va_arg(datas->list, int);

    if(datas->active_flags & FT_PF_FLAG_PRECISION)
        datas->precision = value;
    else{
        datas->active_flags &= FT_PF_FLAG_FIELD_WIDTH;
        datas->field_width = value;
    }
}


int set_flag(char c, t_data *datas){
    int i = MAX_FLAG_OPT;

    while(--i >= 0){
        if(FLAGS[i].flag == c){
            printf("Found flag namely :%c\n", c );
            FLAGS[i].prepare_flag(datas);
            return 1;
        }
    }
    return 0;
}

int set_convert(char c, t_data *datas){
    int i = MAX_CONVERT_OPT;

    while(--i >= 0){
        if(CONVERTS[i].letter == c){
            CONVERTS[i].print(datas);
            //printf("Found convert namely :%c\n", c );
            return 1;
        }
    }
    return 0;
}

void parse_format(t_data *datas){
    int i = -1;
    datas->active_flags = 0;
    while(datas->format_s[(++i) + datas->cursor]){
        if(set_convert(datas->format_s[i + datas->cursor], datas)){
            //printf("Found a convert FOR [%c]i%d:cursor%d, exit\n",datas->format_s[i + datas->cursor], i, datas->cursor);
            datas->cursor += i + 1;
            return;
        }
        else if(set_flag(datas->format_s[i + datas->cursor], datas)){
        }
        else if(ft_isdigit(datas->format_s[i + datas->cursor])){
            //printf("Found a value\n");
        }
        else{

        printf("\nUNDEFINED BEHAVIOR %c\n",datas->format_s[i + datas->cursor]);
            return;
        }
    }
}


int ft_printf(const char *format_s, ...)
{
    int i;
    t_data datas;
    
    datas.format_s = format_s;
    datas.cursor = 0;
    datas.written_count = 0;
    datas.fd = STDOUT_FILENO;
    
    va_start(datas.list, format_s);

    i = 0;
    while(format_s[datas.cursor + i] != '\0')
    {
        if(format_s[datas.cursor + i] == '%')
        {
            ft_putstr_fd_len(format_s + datas.cursor, STDOUT_FILENO, i);
            datas.written_count += i;
            datas.cursor += i + 1;
            i = -1;
            parse_format(&datas);
        }
        i++;
    }
    if (format_s[datas.cursor + i] == '\0'){
        ft_putstr_fd_len(format_s + datas.cursor, STDOUT_FILENO, i);
        datas.written_count += i;
        datas.cursor = i + 1;
    }

    va_end(datas.list);
    return datas.written_count;
}