/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:14:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITTER_E		1

static const t_write g_writer_e[MAX_WRITTER_E] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

#define MAX_SETTER_E		1

static const t_setter g_setter_e[MAX_SETTER_E] = {
	(t_setter){&set_padding_c},
};

int	convert_e(t_data *datas)
{
	return (convert(datas, MAX_SETTER_E, g_setter_e, MAX_WRITTER_E, g_writer_e));
}
