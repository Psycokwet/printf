/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:31:49 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_G		1
static const t_write WRITER_G[MAX_WRITTER_G] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

# define MAX_SETTER_G		1
static const t_setter SETTER_G[MAX_SETTER_G] = {
	(t_setter){&setter_undefined},
};

int convert_g(t_data *datas)
{
    return convert(datas, MAX_SETTER_G, SETTER_G, MAX_WRITTER_G, WRITER_G);
}
