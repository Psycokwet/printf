/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:26:28 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITTER_D		7

static const t_write g_writer_d[MAX_WRITTER_D] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_nbr_buffer},
	(t_write){FT_PF_FLAG_PRECISION, FT_PF_FLAG_PRECISION, &write_precision_d},
	(t_write){FT_PF_FLAG_WRITE | FT_PF_FLAG_PLUS,
		FT_PF_FLAG_WRITE | FT_PF_FLAG_PLUS, &write_value_i_sign},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d_in_buffer},
	(t_write){FT_PF_FLAG_SPACE | FT_PF_FLAG_PLUS, FT_PF_FLAG_SPACE,
		&write_one_space},
};
#define MAX_SETTER_D		2

static const t_setter g_setter_d[MAX_SETTER_D] = {
	(t_setter){&set_value_d},
	(t_setter){&set_padding_c},
};

int	convert_d(t_data *datas)
{
	return (convert(datas, MAX_SETTER_D, g_setter_d, MAX_WRITTER_D,
		g_writer_d));
}
