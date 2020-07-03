/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:31:55 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_F		1
static const t_write WRITER_F[MAX_WRITTER_F] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

# define MAX_SETTER_F		1
static const t_setter SETTER_F[MAX_SETTER_F] = {
	(t_setter){&setter_undefined},
};

int convert_f(t_data *datas)
{
    return convert(datas, MAX_SETTER_F, SETTER_F, MAX_WRITTER_F, WRITER_F);
}
