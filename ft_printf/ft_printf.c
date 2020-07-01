/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/01 10:41:23 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parse_format(t_data *datas)
{
    int ret = -EXIT_FAILURE;
    int command_id = MAX_COMMAND;
    datas->active_flags = 0;
    while(--command_id >= 0){
        //printf("COMMAND :{");
        ret = COMMANDS[command_id].command(datas->format_s + datas->cursor, datas);
        if(ret != 0 ){
            //printf("} COMMAND : %d\n", command_id);
            return ret;
        }
    }
    return -EXIT_FAILURE;
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

    int ret = -EXIT_FAILURE;
    i = 0;
    while(format_s[datas.cursor + i] != '\0')
    {
        if(format_s[datas.cursor + i] == '%')
        {
            ft_putstr_fd_len(format_s + datas.cursor, STDOUT_FILENO, i);
            datas.written_count += i;
            datas.cursor += i + 1;
            i = -1;
            ret = parse_format(&datas);
            if(ret <= -EXIT_FAILURE){
                printf("FAILURE %d\n", ret);
                break;
            }
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
