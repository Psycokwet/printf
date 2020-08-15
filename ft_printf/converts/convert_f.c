/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:14:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITTER_F		1

static const t_write g_writer_f[MAX_WRITTER_F] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

#define MAX_SETTER_F		1

static const t_setter g_setter_f[MAX_SETTER_F] = {
	(t_setter){&set_padding_c},
};

int	convert_f(t_data *datas)
{
	return (convert(datas, MAX_SETTER_F, g_setter_f, MAX_WRITTER_F, g_writer_f));
}
