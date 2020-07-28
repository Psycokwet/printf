/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/28 16:46:21 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define MAX_COMMAND		4
typedef struct		s_command
{
	int			(*command)(const char *, t_data *);
}					t_command;

void set_field_width(t_data *datas, int new_val, char *src){
    (void)src;
//    printf("SET field_width at %d, from %s\n", new_val, src);
    datas->field_width = new_val;
}
void set_precision(t_data *datas, int new_val, char *src){
    (void)src;
//    printf("SET precision at %d, from %s\n", new_val, src);
    datas->precision = new_val;
}

static const t_command COMMANDS[MAX_COMMAND] = {
	(t_command){&set_undefined},
	(t_command){&set_convert},
	(t_command){&set_value},
	(t_command){&set_flag},
};

int parse_format(t_data *datas)
{
    int ret = -EXIT_FAILURE;
    int command_id = MAX_COMMAND;
    datas->active_flags = FT_PF_FLAG_WRITE;
    datas->unauthorized_flags = 0;
    set_field_width(datas, 1, "parse_format");
    //datas->field_width = 1;
    //datas->precision = 1;
    set_precision(datas, 1, "parse_format");
    datas->padding_c = ' ';
    while(--command_id >= 0){
        //printf("COMMAND :{");
        ret = COMMANDS[command_id].command(datas->format_s + datas->cursor, datas);
        //printf("ret = COMMAND [%d]\n", ret);
        if(ret == EXIT_CODE_END_FOUND || ret <= -EXIT_FAILURE){
            //printf("} COMMAND : %d\n", command_id);
            return ret;
        }
        else if(ret == EXIT_CODE_FOUND)
            command_id = MAX_COMMAND;
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
    datas.precision = 1;
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
            datas.last_percent_found = datas.cursor;
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
