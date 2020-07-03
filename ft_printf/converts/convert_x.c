/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 08:19:22 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_X		3
static const t_write WRITER_X[MAX_WRITTER_X] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_x_in_buffer},
	(t_write){FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE, FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE, &write_diese_x},
};

int convert_x(t_data *datas)
{
    return convert(datas, MAX_SETTER_U_X_UP_X, SETTER_U_X_UP_X, MAX_WRITTER_X, WRITER_X);
}
