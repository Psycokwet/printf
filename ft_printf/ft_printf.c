/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/05/20 17:10:02 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

//activated flags, and their value


//malloc, free, write, va_start, va_arg, va_copy, va_end


void print_c(tp_arg_data arg_data){
    char tmp =  va_arg(arg_data->format_data->list, int);

    arg_data->format_data->written_char_count += write(1, &tmp, 1);
}

void print_s(tp_arg_data arg_data){
    char* tmp =  va_arg(arg_data->format_data->list, char*);
    
    arg_data->format_data->written_char_count += write(1, tmp, ft_strlen(tmp));
}
void print_S(tp_arg_data arg_data){//print natural format_s, no arg
    arg_data->format_data->written_char_count += write(1, arg_data->format_data->format_s + arg_data->cursor , arg_data->arg_size);
}
void print_p(tp_arg_data arg_data){
    
}
void print_d(tp_arg_data arg_data){
    
}
void print_i(tp_arg_data arg_data){
    
}
void print_u(tp_arg_data arg_data){
    
}
void print_x(tp_arg_data arg_data){
    
}
void print_X(tp_arg_data arg_data){
    
}

void print_modulo(tp_arg_data arg_data){
    
}

void parse_format(tp_data data)
{
    if(arg_data->code == 'c')
        print_c(arg_data);
    else if(arg_data->code == 's')
        print_s(arg_data);
    else if(arg_data->code == 'p')
        print_p(arg_data);
    else if(arg_data->code == 'd')
        print_d(arg_data);
    else if(arg_data->code == 'i')
        print_i(arg_data);
    else if(arg_data->code == 'u')
        print_u(arg_data);
    else if(arg_data->code == 'x')
        print_x(arg_data);
    else if(arg_data->code == 'X')
        print_X(arg_data);
    else if(arg_data->code == '%')
        print_modulo(arg_data);
}

void print_all_format_format(tp_arg_data arg_data)
{
    if(arg_data->code == 'c')
        print_c(arg_data);
    else if(arg_data->code == 's')
        print_s(arg_data);
    else if(arg_data->code == 'p')
        print_p(arg_data);
    else if(arg_data->code == 'd')
        print_d(arg_data);
    else if(arg_data->code == 'i')
        print_i(arg_data);
    else if(arg_data->code == 'u')
        print_u(arg_data);
    else if(arg_data->code == 'x')
        print_x(arg_data);
    else if(arg_data->code == 'X')
        print_X(arg_data);
    else if(arg_data->code == '%')
        print_modulo(arg_data);
}

void extract_flags(tp_arg_data arg_data){
}

int ft_printf(const char *format_s, ...)
{
    int i;
    tp_data data;

    
    
    data->cursor = 0;
    data->format_s = format_s;




    i = 0;
    while(format_s[i] != '\0')
    {
        if(format_s[i] == '%')
        {
            parse_format(data);
            data->argument_count++;
        }
        i++;
    }
    printf("Aegument count\n", data->argument_count);

    va_start(data->list, data->argument_count);
    va_end(data->list);
    return 0;
}