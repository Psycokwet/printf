/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ext_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/19 16:31:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_itoa_ext_buffer(int nbr, char *buffer, int base, int faux_chiffre)
{
	if (!buffer)
		return (-EXIT_FAILURE);
	if ((nbr < 0))
	{
		buffer[0] = '-';
		return (ft_uitoa_ext_buffer(-nbr, buffer + 1, base, faux_chiffre) + 1);
	}
	else
		return (ft_uitoa_ext_buffer(nbr, buffer, base, faux_chiffre));
	return (-EXIT_FAILURE);
}
