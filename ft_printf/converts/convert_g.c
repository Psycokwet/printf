/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 16:26:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITER_G		1

static const t_write g_writer_g[MAX_WRITER_G] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

#define MAX_SETTER_G		1

static const t_setter g_setter_g[MAX_SETTER_G] = {
	(t_setter){&set_padding_c},
};

int	convert_g(t_data *datas)
{
	datas->current_max_setter = MAX_SETTER_G;
	datas->current_max_writer = MAX_WRITER_G;
	return (convert(datas, g_setter_g, g_writer_g));
}
