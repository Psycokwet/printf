/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:03:28 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_SETTER_C			2

static const t_setter SETTER_C[MAX_SETTER_C] = {
	(t_setter){&set_value_c},
	(t_setter){&set_padding_c},
};

#define MAX_WRITTER_C		3

static const t_write WRITER_C[MAX_WRITTER_C] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding_s},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_c},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH, &write_padding_s},
};

int	convert_c(t_data *datas)
{
	return (convert(datas, MAX_SETTER_C, SETTER_C, MAX_WRITTER_C, WRITER_C));
}
