/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:18:52 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_P		1

static const t_write WRITER_P[MAX_WRITTER_P] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_p},
};

# define MAX_SETTER_P		2
static const t_setter SETTER_P[MAX_SETTER_P] = {
	(t_setter){&set_p_len},
	(t_setter){&set_value_p},
};

int convert_p(t_data *datas)
{
    return convert(datas, MAX_SETTER_P, SETTER_P, MAX_WRITTER_P, WRITER_P);
}
