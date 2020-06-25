/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/06/25 08:07:47 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


void convert_c(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    write(0, &value, 1);
    datas->written_count += 1;
}

void convert_s(t_data *datas)
{
    char *value  = va_arg(datas->list, char*);
    if(!value){
        value = "(null)";
    }
    int len = ft_strlen(value);
    write(0, value, ft_strlen(value));
    datas->written_count += len;
}

void convert_p(t_data *datas)
{
    void *value  = va_arg(datas->list, void*);
    if(!value){
        value = "(nil)";
    }
    int len = ft_strlen(value);
    write(0, value, len);
    datas->written_count += len;
}


static unsigned int		uitoa_len(unsigned int nb, int base)
{
	unsigned int	p;

	p = 1;
	if (nb < 0)
		p++;
	while ((nb) && (nb /= base))
		p++;
	return (p);
}

int ft_itoa_ext_buffer(int nbr, char *buffer, int base, int faux_chiffre)
{
	char			sign;

	if (!buffer)
		return (-1);
	if ((nbr < 0)){
		buffer[0] = '-';
        return (ft_uitoa_ext_buffer(-nbr, buffer + 1, base, faux_chiffre) + 1);
    }
    else
    {
        return (ft_uitoa_ext_buffer(nbr, buffer, base, faux_chiffre));
    }
	return (-1);
}

int ft_uitoa_ext_buffer(unsigned int nbr, char *buffer, int base, int faux_chiffre)
{
	unsigned int	i;
	unsigned int	len;

	if (!buffer)
		return (-1);
    if(base <= 10)
        return (ft_uitoa_ext_buffer_sub_10(nbr, buffer, base));
    return (ft_uitoa_ext_buffer_up_10(nbr, buffer, base, faux_chiffre));
}

int ft_uitoa_ext_buffer_up_10(unsigned int nbr, char *buffer, int base, int faux_chiffre)
{
	unsigned int	i;
	unsigned int	tmp;
	unsigned int	len;

    if (base > 10 || !buffer)
		return (-1);
	len = uitoa_len(nbr, base);
    i = len;
	buffer[i--] = '\0';
	if (!nbr)
		buffer[i--] = '0';
	while (nbr)
	{
        tmp = nbr % base;
		buffer[i--] = (tmp < 10 )? ('0' + tmp) : faux_chiffre + (tmp - 9);
		nbr /= base;
	}
	return (len);
}

int ft_uitoa_ext_buffer_sub_10(unsigned int nbr, char *buffer, int base)
{
	unsigned int	i;
	unsigned int	len;

    if (base > 10 || !buffer)
		return (-1);
	len = uitoa_len(nbr, base);
    i = len;
	buffer[i--] = '\0';
	if (!nbr)
		buffer[i--] = '0';
	while (nbr)
	{
		buffer[i--] = '0' + (nbr % base);
		nbr /= base;
	}
	return (len);
}


void convert_d(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    const int len  = ft_itoa_ext_buffer(value, datas->nbr_buffer, 10, 0);
    if(len == 0)
        return;

    write(0, datas->nbr_buffer, len);
    datas->written_count += len;
}

void convert_u(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 10, 0);
    if(len == 0)
        return;

    write(0, datas->nbr_buffer, len);
    datas->written_count += len;
    
}

void convert_x(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 16, 'a');
    if(len == 0)
        return;

    write(0, datas->nbr_buffer, len);
    datas->written_count += len;
}

void convert_X(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 16, 'A');
    if(len == 0)
        return;

    write(0, datas->nbr_buffer, len);
    datas->written_count += len;
}


void convert_percent(t_data *datas)
{
    char value = '%';
    write(0, &value, 1);
    datas->written_count += 1;
}

int set_flag(char c, t_data *datas){
    int i = MAX_FLAG_OPT;

    while(--i >= 0){
        if(FLAGS[i].flag == c){
            //printf("Found flag namely :%c\n", c );
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