/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/21 13:56:52 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MAX_COMMAND		4

static const t_command g_commands[MAX_COMMAND] = {
	(t_command){&set_undefined},
	(t_command){&set_convert},
	(t_command){&set_value},
	(t_command){&set_flag},
};

int		parse_format(t_data *datas)
{
	int ret;
	int command_id;

	ret = -EXIT_FAILURE;
	command_id = MAX_COMMAND;
	datas->active_flags = FT_PF_FLAG_WRITE;
	datas->unauthorized_flags = 0;
	datas->field_width = 1;
	datas->precision = 1;
	datas->padding_c = ' ';
	while (--command_id >= 0)
	{
		ret = g_commands[command_id].command(datas->format_s + datas->cursor,
			datas);
		if (ret == EXIT_CODE_END_FOUND || ret <= -EXIT_FAILURE)
			return (ret);
		else if (ret == EXIT_CODE_FOUND)
			command_id = MAX_COMMAND;
	}
	return (-EXIT_FAILURE);
}

int		ft_printf_int(t_data *datas)
{
	int		i;
	int		ret;

	i = 0;
	while (datas->format_s[datas->cursor + i] != '\0')
		if (datas->format_s[datas->cursor + i] == '%')
		{
			ret = write(STDOUT_FILENO, datas->format_s + datas->cursor, i);
			if (ret != i)
				return (-EXIT_FAILURE);
			datas->written_count += i;
			datas->cursor += i + 1;
			i = 0;
			datas->last_percent_found = datas->cursor;
			ret = parse_format(datas);
			if (ret <= -EXIT_FAILURE)
				return (-EXIT_FAILURE);
		}
		else
			i++;
	ret = write(STDOUT_FILENO, datas->format_s + datas->cursor, i);
	if (ret != i)
		return (-EXIT_FAILURE);
	datas->written_count += i;
	return (EXIT_SUCCESS);
}

int		ft_printf(const char *format_s, ...)
{
	t_data	datas;
	int		ret;

	datas.format_s = format_s;
	datas.cursor = 0;
	datas.written_count = 0;
	datas.precision = 1;
	datas.fd = STDOUT_FILENO;
	va_start(datas.list, format_s);
	ret = ft_printf_int(&datas);
	va_end(datas.list);
	return (ret == (-EXIT_FAILURE) ? ret : datas.written_count);
}
