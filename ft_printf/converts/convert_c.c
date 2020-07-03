/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:18:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_SETTER_C			1
static const t_setter SETTER_C[MAX_SETTER_C] = {
	(t_setter){&set_value_c},
};

int convert_c(t_data *datas)
{
    return (convert(datas, MAX_SETTER_C, SETTER_C, MAX_WRITTER_C, WRITER_C));
}
