/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_up_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:26:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITTER_UP_X	6

static const t_write g_writer_up_x[MAX_WRITTER_UP_X] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_nbr_buffer},
	(t_write){FT_PF_FLAG_PRECISION, FT_PF_FLAG_PRECISION, &write_precision_d},
	(t_write){FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE,
		FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE, &write_diese_up_x},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_up_x_in_buffer},
};

int	convert_up_x(t_data *datas)
{
	return (convert(datas, MAX_SETTER_X_UP_X, g_setter_x_up_x,
		MAX_WRITTER_UP_X, g_writer_up_x));
}
