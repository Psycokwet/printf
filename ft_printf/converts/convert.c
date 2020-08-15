/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 16:24:07 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	convert(t_data *datas, const t_setter *setter, const t_write *writer)
{
	int ret_writer;
	int i;

	i = datas->current_max_setter;
	if (setter)
		while (i--)
			setter[i].setter(datas);
	i = datas->current_max_writer;
	if (writer)
		while (i--)
		{
			if (!((datas->active_flags & writer[i].flags_concerned)
				== writer[i].flags_awaited))
				continue;
			ret_writer = writer[i].write(datas);
			if (ret_writer < EXIT_SUCCESS)
				return (-EXIT_FAILURE);
			datas->written_count += ret_writer;
		}
	return (EXIT_CODE_END_FOUND);
}
