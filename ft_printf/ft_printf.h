/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/21 14:47:52 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define EXIT_CODE_END_FOUND	2
# define EXIT_CODE_FOUND		1
# define EXIT_CODE_NOT_FOUND	0

# define MAX_NBR_LENGTH	    	30

typedef struct		s_data
{
	int				fd;
	int				cursor;
	int				last_percent_found;
	int				padding_c;
	size_t			len;
	int				written_count;
	const char		*format_s;
	char			nbr_buffer[MAX_NBR_LENGTH];
	int				precision;
	int				field_width;
	unsigned int	active_flags;
	unsigned int	unauthorized_flags;
	va_list			list;
	char			*value_s;
	void			*value_p;
	int				value_i;
	unsigned int	value_ui;
	int				current_max_setter;
	int				current_max_writer;
}					t_data;

typedef struct		s_str
{
	char			*str;
	size_t			size;
}					t_str;

# define FT_PF_FLAG_WRITE		0
# define FT_PF_FLAG_ZERO		1u
# define FT_PF_FLAG_LESS		2u
# define FT_PF_FLAG_FIELD_WIDTH	4u
# define FT_PF_FLAG_PRECISION	8u
# define FT_PF_FLAG_DIESE		16u
# define FT_PF_FLAG_SPACE		32u
# define FT_PF_FLAG_PLUS		64u
# define FT_PF_FLAG_L			128u
# define FT_PF_FLAG_LL			256u
# define FT_PF_FLAG_H			514u
# define FT_PF_FLAG_HH			1024u
# define FT_PF_NEG_PRECISION	2048u
# define FT_PF_NEG_FIELD_WIDTH	4096u
# define FT_PF_WC_PRECISION		8192u
# define FT_PF_NO_FLAG			0

/*
** # define FT_PF_FLAG_WRITE		(1u << 0)
** # define FT_PF_FLAG_ZERO			(1u << 1)
** # define FT_PF_FLAG_LESS			(1u << 2)
** # define FT_PF_FLAG_FIELD_WIDTH	(1u << 3)
** # define FT_PF_FLAG_PRECISION	(1u << 4)
** # define FT_PF_FLAG_DIESE		(1u << 5)
** # define FT_PF_FLAG_SPACE		(1u << 6)
** # define FT_PF_FLAG_PLUS			(1u << 7)
** # define FT_PF_FLAG_L			(1u << 8)
** # define FT_PF_FLAG_LL			(1u << 9)
** # define FT_PF_FLAG_H			(1u << 10)
** # define FT_PF_FLAG_HH			(1u << 11)
** # define FT_PF_NEG_PRECISION		(1u << 12)
** # define FT_PF_NEG_FIELD_WIDTH	(1u << 13)
** # define FT_PF_WC_PRECISION		(1u << 14)
** # define FT_PF_NO_FLAG			0
*/

typedef struct		s_command
{
	int				(*command)(const char *, t_data *);
}					t_command;

int				ft_printf(const char *format_s, ...);
#endif
