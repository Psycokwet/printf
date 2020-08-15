/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 16:26:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_SETTER_PERCENT		1

static const t_setter g_setter_percent[MAX_SETTER_PERCENT] = {
	(t_setter){&set_value_percent},
};

#define MAX_WRITER_PERCENT	1

static const t_write g_writer_percent[MAX_WRITER_PERCENT] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_c},
};

int	convert_percent(t_data *datas)
{
	datas->current_max_setter = MAX_SETTER_PERCENT;
	datas->current_max_writer = MAX_WRITER_PERCENT;
	return (convert(datas, g_setter_percent, g_writer_percent));
}
