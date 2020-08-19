/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_ext_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/19 16:33:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_uitoa_ext_buffer(unsigned int nbr, char *buffer, int base,
	int faux_chiffre)
{
	if (!buffer)
		return (-EXIT_FAILURE);
	if (base <= 10)
		return (ft_uitoa_ext_buffer_sub_10(nbr, buffer, base));
	return (ft_uitoa_ext_buffer_up_10(nbr, buffer, base, faux_chiffre));
}
