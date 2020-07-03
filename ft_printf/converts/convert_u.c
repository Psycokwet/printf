/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 09:01:35 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_U		2
static const t_write WRITER_U[MAX_WRITTER_U] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_nbr_buffer},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_u_in_buffer},
};

int convert_u(t_data *datas)
{
    return convert(datas, MAX_SETTER_U_X_UP_X, SETTER_U_X_UP_X, MAX_WRITTER_U, WRITER_U);
}
