/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_ext_buffer_up_10.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/25 16:20:24 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_uitoa_ext_buffer_up_10(unsigned long long int nbr, char *buffer,
	int base, int faux_chiffre)
{
	unsigned long	i;
	unsigned long	tmp;
	unsigned long	len;

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
		buffer[i--] = (tmp < 10) ? ('0' + tmp) : faux_chiffre + (tmp - 10);
		nbr /= base;
	}
	return (len);
}
