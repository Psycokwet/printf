/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:17:04 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITTER_N		1

static const t_write g_writer_n[MAX_WRITTER_N] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

#define MAX_SETTER_N		1

static const t_setter g_setter_n[MAX_SETTER_N] = {
	(t_setter){&setter_undefined},
};

int	convert_n(t_data *datas)
{
	return (convert(datas, MAX_SETTER_N, g_setter_n, MAX_WRITTER_N,
		g_writer_n));
}
