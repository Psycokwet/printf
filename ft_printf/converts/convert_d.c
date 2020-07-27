/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/27 14:14:15 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


# define MAX_WRITTER_D		6
static const t_write WRITER_D[MAX_WRITTER_D] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_nbr_buffer},
	(t_write){FT_PF_FLAG_PRECISION, FT_PF_FLAG_PRECISION, &write_precision_d},
	(t_write){FT_PF_FLAG_WRITE | FT_PF_FLAG_PLUS, FT_PF_FLAG_WRITE | FT_PF_FLAG_PLUS, &write_value_i_sign},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH, &write_padding_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d_in_buffer},
};
# define MAX_SETTER_D		2
static const t_setter SETTER_D[MAX_SETTER_D] = {
	(t_setter){&set_value_d},
	(t_setter){&set_padding_c},
};

int convert_d(t_data *datas)
{
    return convert(datas, MAX_SETTER_D, SETTER_D, MAX_WRITTER_D, WRITER_D);
}
