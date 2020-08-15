/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 16:43:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

int set_flag(const char *code, t_data *datas)
{
	int i = MAX_FLAG_OPT;

	while (--i >= 0)
	{
		if (ft_strncmp(g_flags[i].code.str, code, g_flags[i].code.size) == 0)
		{
			datas->cursor += g_flags[i].code.size;
			g_flags[i].prepare_flag(datas);
			return (EXIT_CODE_FOUND);
		}
	}
	return (EXIT_CODE_NOT_FOUND);
}
