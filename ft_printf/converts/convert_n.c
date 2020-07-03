/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:31:44 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_N		1
static const t_write WRITER_N[MAX_WRITTER_N] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

# define MAX_SETTER_N		1
static const t_setter SETTER_N[MAX_SETTER_N] = {
	(t_setter){&setter_undefined},
};

int convert_n(t_data *datas)
{
    return convert(datas, MAX_SETTER_N, SETTER_N, MAX_WRITTER_N, WRITER_N);
}
