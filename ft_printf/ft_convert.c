/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 14:08:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_c(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    int ret_read;

    ret_read = write(datas->fd, &value, 1);
    if (ret_read < 0)
        return (-EXIT_FAILURE);
    datas->written_count += ret_read;
    return (EXIT_CODE_END_FOUND);
}

int write_padding(t_data *datas)
{
    int ret_read;
    int padding_count;
    //printf("write_padding W :[%d] P:[%d]\n",  datas->field_width, datas->precision);
    padding_count = 0;
    while (padding_count < datas->field_width)
    {
        ret_read = write(datas->fd, &(datas->padding_c), 1);
        padding_count += ret_read;
        if (ret_read < 0 )
            return (-EXIT_FAILURE);
    }
    if (padding_count < 0 || padding_count != datas->field_width)
        return (-EXIT_FAILURE);
    return (padding_count);
}

void set_padding_c(t_data *datas)
{
    if (datas->active_flags & FT_PF_FLAG_ZERO)
        datas->padding_c = '0';
    else
        datas->padding_c = ' ';
}
void set_s_len(t_data *datas)
{
    datas->len = ft_strlen(datas->value_s);
    //printf(" W :[%d] P:[%d] L: [%ld]\n",  datas->field_width, datas->precision, datas->len);
    if (datas->active_flags & FT_PF_FLAG_PRECISION)
    {
        if (datas->len > (size_t)datas->precision)
            datas->len = datas->precision;
        else
            datas->precision = 0;
        if (datas->field_width > datas->precision)
            datas->field_width -= datas->precision;
        else
            datas->field_width = 0;
    }
}

void set_value_s(t_data *datas)
{
    datas->value_s  = va_arg(datas->list, char*);
    if (!datas->value_s)
        datas->value_s = "(null)";
}

int    write_s(t_data *datas)
{
    int ret_read;
    //printf("WRITE\n");
    ret_read = write(datas->fd, datas->value_s, datas->len);
    if (ret_read < 0 || (size_t)ret_read != datas->len)
        return (-EXIT_FAILURE);
    return (ret_read);
}

int convert(t_data *datas, int max_setter, const t_setter *setter, int max_writer, const t_write *writer)
{
    int ret_writer;
    int i ;
    
    i = max_setter;
    while (i--)
        setter[i].setter(datas);

    i = max_writer;
    while (i--)
    { 
        if (!((datas->active_flags & writer[i].flags_concerned) == writer[i].flags_awaited))
            continue;
        ret_writer = writer[i].write(datas);
        if (ret_writer < EXIT_SUCCESS)
            return (-EXIT_FAILURE);
        datas->written_count += ret_writer;
    }
    //datas->written_count += ret_read + padding;
    return (EXIT_CODE_END_FOUND);
}

int convert_s(t_data *datas)
{
    return convert(datas, MAX_SETTER_S, SETTER_S, MAX_WRITTER_S, WRITER_S);
}

void set_p_len(t_data *datas)
{
    if (datas->value_p){
        printf("NEED IMPLEMENTATION\n");
        return;
    }
    set_s_len(datas);
}

void set_value_p(t_data *datas)
{
    datas->value_p  = va_arg(datas->list, char*);
    if (datas->value_p){
        printf("NEED IMPLEMENTATION\n");
        return;
    }
    datas->value_s = "(nil)";
    datas->len = ft_strlen(datas->value_s);
}

int    write_p(t_data *datas)
{
    if (datas->value_p)
    {
        //do something else for Oxqsdhh
        printf("NEED IMPLEMENTATION\n");
        return EXIT_FAILURE;
    }
    return write_s(datas);
}

int convert_p(t_data *datas)
{
    return convert(datas, MAX_SETTER_P, SETTER_P, MAX_WRITTER_P, WRITER_P);
}

int convert_d(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    const int len  = ft_itoa_ext_buffer(value, datas->nbr_buffer, 10, 0);
    int ret_read;
    if (len == 0)
        return (-EXIT_FAILURE);


    ret_read = write(datas->fd, datas->nbr_buffer, len);
    if (ret_read < 0)
        return (-EXIT_FAILURE);
    datas->written_count += ret_read;
    return (EXIT_CODE_END_FOUND);
}

int convert_u(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 10, 0);
    int ret_read;
    if (len == 0)
        return (-EXIT_FAILURE);


    ret_read = write(datas->fd, datas->nbr_buffer, len);
    if (ret_read < 0)
        return (-EXIT_FAILURE);
    datas->written_count += ret_read;
    return (EXIT_CODE_END_FOUND);    
}

int convert_x(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 16, 'a');
    int ret_read;
    if (len == 0)
        return (-EXIT_FAILURE);

    ret_read = write(datas->fd, datas->nbr_buffer, len);
    if (ret_read != len)
        return (-EXIT_FAILURE);
    datas->written_count += ret_read;
    return (EXIT_CODE_END_FOUND);
}

int convert_up_x(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 16, 'A');
    int ret_read;
    //printf("AH convert_up_x \n");
    if (len == 0)
        return (-EXIT_FAILURE);
    ret_read = write(datas->fd, datas->nbr_buffer, len);
    if (ret_read != len)
        return (-EXIT_FAILURE);
    datas->written_count += ret_read;
    return (EXIT_CODE_END_FOUND);
}


int convert_percent(t_data *datas)
{
    char value = '%';
    int ret_read;

    ret_read = write(datas->fd, &value, 1);
    if (ret_read < 0)
        return (-EXIT_FAILURE);
    datas->written_count += ret_read;
    return (EXIT_CODE_END_FOUND);
}
