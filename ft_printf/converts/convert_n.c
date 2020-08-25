/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/25 15:36:19 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITER_N		1

static const t_write g_writer_n[MAX_WRITER_N] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_no_writer},
};

#define MAX_SETTER_N		1

static const t_setter g_setter_n[MAX_SETTER_N] = {
	(t_setter){&setter_outer_int_n},
};

int	convert_n(t_data *datas)
{
	datas->current_max_setter = MAX_SETTER_N;
	datas->current_max_writer = MAX_WRITER_N;
	return (convert(datas, g_setter_n, g_writer_n));
}
