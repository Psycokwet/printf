/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 16:55:42 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
    	return (-EXIT_FAILURE);
	if ((nbr < 0)){
		buffer[0] = '-';
        return (ft_uitoa_ext_buffer(-nbr, buffer + 1, base, faux_chiffre) + 1);
    }
    else
        return (ft_uitoa_ext_buffer(nbr, buffer, base, faux_chiffre));
    return (-EXIT_FAILURE);
}

int ft_uitoa_ext_buffer(unsigned int nbr, char *buffer, int base, int faux_chiffre)
{
	if (!buffer)
    	return (-EXIT_FAILURE);
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
		return (-EXIT_FAILURE);
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
		return (-EXIT_FAILURE);
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
