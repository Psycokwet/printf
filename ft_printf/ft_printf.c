/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 14:54:28 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MAX_COMMAND		4
typedef struct		s_command
{
	int			(*command)(const char *, t_data *);
}					t_command;

static const t_command COMMANDS[MAX_COMMAND] = {
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
	while (--command_id >= 0){
		ret = COMMANDS[command_id].command(datas->format_s + datas->cursor, datas);
		if (ret == EXIT_CODE_END_FOUND || ret <= -EXIT_FAILURE)
			return (ret);
		else if (ret == EXIT_CODE_FOUND)
			command_id = MAX_COMMAND;
	}
	return (-EXIT_FAILURE);
}

int		ft_printf(const char *format_s, ...)
{
	int i;
	t_data datas;

	datas.format_s = format_s;
	datas.cursor = 0;
	datas.written_count = 0;
	datas.precision = 1;
	datas.fd = STDOUT_FILENO;
	va_start(datas.list, format_s);
	int ret = -EXIT_FAILURE;
	i = 0;
	while (format_s[datas.cursor + i] != '\0')
	{
		if (format_s[datas.cursor + i] == '%')
		{
			ft_putstr_fd_len(format_s + datas.cursor, STDOUT_FILENO, i);
			datas.written_count += i;
			datas.cursor += i + 1;
			i = -1;
			datas.last_percent_found = datas.cursor;
			ret = parse_format(&datas);
			if (ret <= -EXIT_FAILURE)
				break;
		}
		i++;
	}
	if (format_s[datas.cursor + i] == '\0'){
		ft_putstr_fd_len(format_s + datas.cursor, STDOUT_FILENO, i);
		datas.written_count += i;
		datas.cursor = i + 1;
	}
	va_end(datas.list);
	return (datas.written_count);
}
