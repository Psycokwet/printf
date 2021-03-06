/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 16:26:26 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITER_S		3

static const t_write g_writer_s[MAX_WRITER_S] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding_s},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_s},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS,
		FT_PF_FLAG_FIELD_WIDTH, &write_padding_s},
};

#ifndef LINUX

# define MAX_SETTER_S		3

static const t_setter g_setter_s[MAX_SETTER_S] = {
	(t_setter){&set_s_len},
	(t_setter){&set_value_s},
	(t_setter){&set_padding_c},
};

#else

# define MAX_SETTER_S		2

static const t_setter g_setter_s[MAX_SETTER_S] = {
	(t_setter){&set_s_len},
	(t_setter){&set_value_s},
};

#endif

int	convert_s(t_data *datas)
{
	datas->current_max_setter = MAX_SETTER_S;
	datas->current_max_writer = MAX_WRITER_S;
	return (convert(datas, g_setter_s, g_writer_s));
}
