/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_args_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:36:16 by scarboni          #+#    #+#             */
/*   Updated: 2020/05/13 16:57:15 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

//activated flags, and their value


//malloc, free, write, va_start, va_arg, va_copy, va_end


void print_c(tp_data data){
    int tmp =  va_arg(data->list, int);
    ft_putchar_fd(tmp, 1);
}
void print_s(tp_data data){
    char * tmp =  va_arg(data->list, char *);
    write(1, tmp , ft_strlen(tmp));
}
void print_S(tp_data data){
    char * tmp =  va_arg(data->list, char *);
    write(1, tmp , ft_strlen(tmp));
}
void print_p(tp_data data){
    
}
void print_d(tp_data data){
    
}
void print_i(tp_data data){
    
}
void print_u(tp_data data){
    
}
void print_x(tp_data data){
    
}
void print_X(tp_data data){
    
}

void print_modulo(tp_data data){
    
}

void parse_format(tp_data data)
{
    if(data->code == 'c')
        print_c(data);
    else if(data->code == 's')
        print_s(data);
    else if(data->code == 'p')
        print_p(data);
    else if(data->code == 'd')
        print_d(data);
    else if(data->code == 'i')
        print_i(data);
    else if(data->code == 'u')
        print_u(data);
    else if(data->code == 'x')
        print_x(data);
    else if(data->code == 'X')
        print_X(data);
    else if(data->code == '%')
        print_modulo(data);
}

void extract_flags(tp_data data){
    (void) data;
}

int ft_printf(const char *format_s, ...)
{
    int i;
    tp_data data;

    
    
    data->cursor = 0;
    data->format_s = format_s;

    va_start(data->list, 2);




    i = 0;
    while(format_s[i] != '\0')
    {
        if(format_s[i] == '%')
        {
            write(1, data->format_s + data->cursor , i);
            data->cursor = i;
            parse_format(data);
        }
        i++;
    }
    va_end(list);
    return 0;
}