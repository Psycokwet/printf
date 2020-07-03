/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 07:19:44 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define MAX_SETTER_PERCENT		1
static const t_setter SETTER_PERCENT[MAX_SETTER_PERCENT] = {
	(t_setter){&set_value_percent},
};

int convert_percent(t_data *datas)
{
    return (convert(datas, MAX_SETTER_PERCENT, SETTER_PERCENT, MAX_WRITTER_C, WRITER_C));
}
