/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 18:43:23 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_S		3

static const t_write WRITER_S[MAX_WRITTER_S] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_s},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH, &write_padding},
};

#ifndef LINUX

# define MAX_SETTER_S		3

static const t_setter SETTER_S[MAX_SETTER_S] = {
	(t_setter){&set_s_len},
	(t_setter){&set_value_s},
	(t_setter){&set_padding_c},
};

#else

# define MAX_SETTER_S		2

static const t_setter SETTER_S[MAX_SETTER_S] = {
	(t_setter){&set_s_len},
	(t_setter){&set_value_s},
};

#endif
int convert_s(t_data *datas)
{
    return convert(datas, MAX_SETTER_S, SETTER_S, MAX_WRITTER_S, WRITER_S);
}
