/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:41:14 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


# define MAX_WRITTER_D		2
static const t_write WRITER_D[MAX_WRITTER_D] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d_in_buffer},
};

# define MAX_SETTER_D		1
static const t_setter SETTER_D[MAX_SETTER_D] = {
	(t_setter){&set_value_d},
};

int convert_d(t_data *datas)
{
    return convert(datas, MAX_SETTER_D, SETTER_D, MAX_WRITTER_D, WRITER_D);
}
