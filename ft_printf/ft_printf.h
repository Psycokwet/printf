/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/25 10:12:58 by scarboni         ###   ########.fr       */
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
	unsigned long	active_flags;
	unsigned long	unauthorized_flags;
	va_list			list;
	char			*value_s;
	void			*value_p; //Long long int
	int				value_i;
	unsigned long	value_u;
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

int					ft_printf(const char *format_s, ...);
void				set_width_precision_u(t_data *datas);
void				set_width_precision_x_up_x(t_data *datas);
void				set_precision_or_fieldwith(t_data *datas, const int value);
int					write_diese_x_up_x(t_data *datas, char *diese);
int					write_padding(t_data *datas, const int padding_c,
						const int padding_max);
int					write_str(int fd, char *str, size_t len);
int					write_ui_value_in_buffer(t_data *datas);
int					write_uix_value_in_buffer(t_data *datas, int base,
						char fauxchiffre);

/*
** ************************************************************************** **
** 									PREPARE_FLAGS                             **
** ************************************************************************** **
*/

void				prepare_flag_less(t_data *datas);
void				prepare_flag_0(t_data *datas);
void				prepare_flag_precision(t_data *datas);
void				prepare_flag_wild_card(t_data *datas);
void				prepare_flag_diese(t_data *datas);
void				prepare_flag_space(t_data *datas);
void				prepare_flag_plus(t_data *datas);
void				prepare_flag_l(t_data *datas);
void				prepare_flag_ll(t_data *datas);
void				prepare_flag_h(t_data *datas);
void				prepare_flag_hh(t_data *datas);

# define MAX_FLAG_OPT	    	11

typedef struct		s_flag
{
	t_str			code;
	unsigned long	override_flags;
	void			(*prepare_flag)(t_data *);
}					t_flag;

static const t_flag g_flags[MAX_FLAG_OPT] = {
	(t_flag){(t_str){"-", 1u}, FT_PF_FLAG_ZERO, &prepare_flag_less},
	(t_flag){(t_str){"0", 1u}, FT_PF_NO_FLAG, &prepare_flag_0},
	(t_flag){(t_str){".", 1u}, FT_PF_NO_FLAG, &prepare_flag_precision},
	(t_flag){(t_str){"*", 1u}, FT_PF_NO_FLAG, &prepare_flag_wild_card},
	(t_flag){(t_str){"#", 1u}, FT_PF_NO_FLAG, &prepare_flag_diese},
	(t_flag){(t_str){" ", 1u}, FT_PF_NO_FLAG, &prepare_flag_space},
	(t_flag){(t_str){"+", 1u}, FT_PF_NO_FLAG, &prepare_flag_plus},
	(t_flag){(t_str){"l", 1u}, FT_PF_NO_FLAG, &prepare_flag_l},
	(t_flag){(t_str){"ll", 1u}, FT_PF_NO_FLAG, &prepare_flag_ll},
	(t_flag){(t_str){"h", 1u}, FT_PF_NO_FLAG, &prepare_flag_h},
	(t_flag){(t_str){"hh", 1u}, FT_PF_NO_FLAG, &prepare_flag_hh},
};

/*
** ************************************************************************** **
** 									NBR_MANAGEMENT                            **
** ************************************************************************** **
*/

size_t				strlen_from_int(int value);
unsigned long		uitoa_len(unsigned long nb, int base);
int					ft_itoa_ext_buffer(int nbr, char *buffer, int base,
						int faux_chiffre);
int					ft_uitoa_ext_buffer(unsigned long nbr, char *buffer,
						int base, int faux_chiffre);
int					ft_uitoa_ext_buffer_up_10(unsigned long nbr, char *buffer,
						int base, int faux_chiffre);
int					ft_uitoa_ext_buffer_sub_10(unsigned long nbr, char *buffer,
						int base);

/*
** ************************************************************************** **
** 									SETTERS                                   **
** ************************************************************************** **
*/

typedef struct		s_setter
{
	void			(*setter)(t_data *);
}					t_setter;

void				set_correct_diese(t_data *datas);
void				set_diese_cost(t_data *datas);
void				set_padding_c(t_data *datas);
void				set_s_len(t_data *datas);
void				set_value_c(t_data *datas);
void				set_value_d(t_data *datas);
void				set_value_p(t_data *datas);
void				set_value_percent(t_data *datas);
void				set_padding_c(t_data *datas);
void				set_s_len(t_data *datas);
void				set_value_s(t_data *datas);
void				set_value_ui(t_data *datas);
void				setter_undefined(t_data *datas);

# define MAX_SETTER_X_UP_X		3

static const t_setter g_setter_x_up_x[MAX_SETTER_X_UP_X] = {
	(t_setter){&set_correct_diese},
	(t_setter){&set_value_ui},
	(t_setter){&set_padding_c},
};

/*
** ************************************************************************** **
** 									WRITERS                                   **
** ************************************************************************** **
*/

int					write_c(t_data *datas);
int					write_nbr_buffer(t_data *datas);
int					write_one_space(t_data *datas);
int					write_d_in_buffer(t_data *datas);
int					write_diese_up_x(t_data *datas);
int					write_diese_x(t_data *datas);
int					write_p(t_data *datas);
int					write_p_in_buffer(t_data *datas);
int					write_padding_s(t_data *datas);
int					write_padding_d(t_data *datas);
int					write_0_d(t_data *datas);
int					write_precision_d(t_data *datas);
int					write_s(t_data *datas);
int					write_u_in_buffer(t_data *datas);
int					write_up_x_in_buffer(t_data *datas);
int					write_value_i_sign(t_data *datas);
int					write_x_in_buffer(t_data *datas);
int					writer_undefined(t_data *datas);

typedef struct		s_write
{
	unsigned long	flags_concerned;
	unsigned long	flags_awaited;
	int				(*write)(t_data *);
}					t_write;

/*
** ************************************************************************** **
** 									COMMANDS                                  **
** ************************************************************************** **
*/

typedef struct		s_convert
{
	t_str			code;
	int				(*print)(t_data *);
}					t_convert;

int					set_undefined(const char *str_start, t_data *datas);
int					set_convert(const char *str_start, t_data *datas);
int					set_value(const char *str_start, t_data *datas);
int					set_flag(const char *str_start, t_data *datas);

/*
** ************************************************************************** **
** 									CONVERTS                                  **
** ************************************************************************** **
*/

int					convert(t_data *datas, const t_setter *setter,
						const t_write *writer);
int					convert_c(t_data *datas);
int					convert_s(t_data *datas);
int					convert_p(t_data *datas);
int					convert_d(t_data *datas);
int					convert_u(t_data *datas);
int					convert_x(t_data *datas);
int					convert_up_x(t_data *datas);
int					convert_percent(t_data *datas);
int					convert_n(t_data *datas);
int					convert_f(t_data *datas);
int					convert_g(t_data *datas);
int					convert_e(t_data *datas);

#endif
