/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_from_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/19 16:32:29 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	strlen_from_int(int value)
{
	size_t result;

	result = 0;
	if (value < 0)
	{
		value = -value;
		result++;
	}
	else if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / 10;
		result++;
	}
	return (result);
}
