/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_up_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 09:01:45 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_UP_X	3
static const t_write WRITER_UP_X[MAX_WRITTER_UP_X] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_nbr_buffer},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_up_x_in_buffer},
	(t_write){FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE, FT_PF_FLAG_WRITE | FT_PF_FLAG_DIESE, &write_diese_up_x},
};

int convert_up_x(t_data *datas)
{
    return convert(datas, MAX_SETTER_U_X_UP_X, SETTER_U_X_UP_X, MAX_WRITTER_UP_X, WRITER_UP_X);
}
