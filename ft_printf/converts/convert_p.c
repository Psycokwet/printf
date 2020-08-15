/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:27:19 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITTER_P		6

static const t_write g_writer_p[MAX_WRITTER_P] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_p},
	(t_write){FT_PF_FLAG_PRECISION, FT_PF_FLAG_PRECISION, &write_precision_d},
	(t_write){FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE,
		FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE, &write_diese_x},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_p_in_buffer},
};

#define MAX_SETTER_P		2

static const t_setter g_setter_p[MAX_SETTER_P] = {
	(t_setter){&set_diese_cost},
	(t_setter){&set_value_p},
};

int	convert_p(t_data *datas)
{
	return (convert(datas, MAX_SETTER_P, g_setter_p, MAX_WRITTER_P,
		g_writer_p));
}
