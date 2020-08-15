/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 16:26:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITER_F		1

static const t_write g_writer_f[MAX_WRITER_F] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

#define MAX_SETTER_F		1

static const t_setter g_setter_f[MAX_SETTER_F] = {
	(t_setter){&set_padding_c},
};

int	convert_f(t_data *datas)
{
	datas->current_max_setter = MAX_SETTER_F;
	datas->current_max_writer = MAX_WRITER_F;
	return (convert(datas, g_setter_f, g_writer_f));
}
