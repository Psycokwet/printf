/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_undefined.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 20:13:19 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#ifndef LINUX

int	set_undefined(const char *code, t_data *datas)
{
	(void)code;
	(void)datas;
	return (EXIT_CODE_END_FOUND);
}

#else

int	set_undefined(const char *code, t_data *datas)
{
	int ret;

	ret = convert_percent(datas);
	(void)code;
	if (ret < EXIT_SUCCESS)
		return (-EXIT_FAILURE);
	datas->cursor = datas->last_percent_found;
	return (EXIT_CODE_END_FOUND);
}

#endif
