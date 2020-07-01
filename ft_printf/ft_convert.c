/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/06/30 21:25:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void convert_c(t_data *datas)
{
    const int value  = va_arg(datas->list, int);
    write(datas->fd, &value, 1);
    datas->written_count += 1;
}

void convert_s(t_data *datas)
{
    char *value  = va_arg(datas->list, char*);
    if(!value){
        value = "(null)";
    }
    int len = ft_strlen(value);
    write(datas->fd, value, ft_strlen(value));
    datas->written_count += len;
}

void convert_p(t_data *datas)
{
    void *value  = va_arg(datas->list, void*);
    if(!value){
        value = "(nil)";
    }
    int len = ft_strlen(value);
    write(datas->fd, value, len);
    datas->written_count += len;
}


unsigned int		uitoa_len(unsigned int nb, int base)
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
	if (!buffer)
		return (-1);
	if ((nbr < 0)){
		buffer[0] = '-';
        return (ft_uitoa_ext_buffer(-nbr, buffer + 1, base, faux_chiffre) + 1);
    }
    else
        return (ft_uitoa_ext_buffer(nbr, buffer, base, faux_chiffre));
    return (-1);
}

int ft_uitoa_ext_buffer(unsigned int nbr, char *buffer, int base, int faux_chiffre)
{
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

    if (!buffer)
		return (-1);
	len = uitoa_len(nbr, base);
    i = len;
	buffer[i--] = '\0';
	if (!nbr)
		buffer[i--] = '0';
	while (nbr)
	{
        tmp = nbr % base;
		buffer[i--] = (tmp < 10 )? ('0' + tmp) : faux_chiffre + (tmp - 10);
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

    write(datas->fd, datas->nbr_buffer, len);
    datas->written_count += len;
}

void convert_u(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 10, 0);
    if(len == 0)
        return;

    write(datas->fd, datas->nbr_buffer, len);
    datas->written_count += len;
    
}

void convert_x(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 16, 'a');
    if(len == 0)
        return;
    write(datas->fd, datas->nbr_buffer, len);
    datas->written_count += len;
}

void convert_up_x(t_data *datas)
{
    const unsigned int value  = va_arg(datas->list, unsigned int);
    const int len  = ft_uitoa_ext_buffer(value, datas->nbr_buffer, 16, 'A');
    if(len == 0)
        return;
    write(datas->fd, datas->nbr_buffer, len);
    datas->written_count += len;
}


void convert_percent(t_data *datas)
{
    char value = '%';
    write(datas->fd, &value, 1);
    datas->written_count += 1;
}
