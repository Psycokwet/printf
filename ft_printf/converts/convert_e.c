/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:32:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_WRITTER_E		1
static const t_write WRITER_E[MAX_WRITTER_E] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &writer_undefined},
};

# define MAX_SETTER_E		1
static const t_setter SETTER_E[MAX_SETTER_E] = {
	(t_setter){&setter_undefined},
};

int convert_e(t_data *datas)
{
    return convert(datas, MAX_SETTER_E, SETTER_E, MAX_WRITTER_E, WRITER_E);
}
