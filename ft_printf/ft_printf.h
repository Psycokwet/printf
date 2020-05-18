/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/05/13 16:17:55 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"


typedef struct s_argument_data{
    char code;
    int cursor;
    size_t arg_size;
    tp_data format_data;
} t_arg_data, *tp_arg_data;

typedef struct s_data{
    va_list list;
    int cursor;
    int argument_count;
    int written_char_count;
    const char *format_s;
    t_list arguments; // Must contain an s_argument_data
} t_data, *tp_data;

int ft_printf(const char *, ...);


void print_c(tp_arg_data arg_data);
void print_s(tp_arg_data arg_data);
// to print part of format_s directly
void print_S(tp_arg_data arg_data);
void print_p(tp_arg_data arg_data);
void print_d(tp_arg_data arg_data);
void print_i(tp_arg_data arg_data);
void print_u(tp_arg_data arg_data);
void print_x(tp_arg_data arg_data);
void print_X(tp_arg_data arg_data);
void print_modulo(tp_arg_data arg_data);

#endif