/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_up_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:46:15 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_UP_X	2
static const t_write WRITER_UP_X[MAX_WRITTER_UP_X] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_up_x_in_buffer},
};

int convert_up_x(t_data *datas)
{
    return convert(datas, MAX_SETTER_U, SETTER_U, MAX_WRITTER_UP_X, WRITER_UP_X);
}
