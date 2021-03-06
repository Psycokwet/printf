/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 16:26:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_SETTER_C			2

static const t_setter g_setter_c[MAX_SETTER_C] = {
	(t_setter){&set_value_c},
	(t_setter){&set_padding_c},
};

#define MAX_WRITER_C		3

static const t_write g_writer_c[MAX_WRITER_C] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding_s},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_c},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH,
		&write_padding_s},
};

int	convert_c(t_data *datas)
{
	datas->current_max_setter = MAX_SETTER_C;
	datas->current_max_writer = MAX_WRITER_C;
	return (convert(datas, g_setter_c, g_writer_c));
}
