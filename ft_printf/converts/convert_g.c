/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 15:13:54 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_WRITTER_G		1

static const t_write g_writer_g[MAX_WRITTER_G] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

#define MAX_SETTER_G		1

static const t_setter g_setter_g[MAX_SETTER_G] = {
	(t_setter){&set_padding_c},
};

int	convert_g(t_data *datas)
{
	return (convert(datas, MAX_SETTER_G, g_setter_g, MAX_WRITTER_G, g_writer_g));
}
