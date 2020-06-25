/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/06/25 08:07:34 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

# define MAX_NBR_LENGTH	    	30
typedef struct		s_data
{
	int				cursor;
	int				written_count;
	const char		*format_s;
	char			nbr_buffer[MAX_NBR_LENGTH];
    va_list			list;
}					t_data;

# define MAX_FLAG_OPT	    	4

typedef struct		s_flag
{
	int				flag;
	char			*valid_convert;
	char			*override_flags;
}					t_flag;

static const t_flag FLAGS[MAX_FLAG_OPT] = {
	(t_flag){'-', "", "0"},
	(t_flag){'0', "diouxXaAeEfFgG", ""},
	(t_flag){'.', "", ""},
	(t_flag){'*', "", ""},
};





# define MAX_CONVERT_OPT		9
typedef struct		s_convert
{
	int				letter;
	void			(*print)(t_data *);
}					t_convert;

//converts :

void convert_c(t_data *datas);
void convert_s(t_data *datas);
void convert_p(t_data *datas);
void convert_d(t_data *datas);
void convert_u(t_data *datas);
void convert_x(t_data *datas);
void convert_X(t_data *datas);
void convert_percent(t_data *datas);

static const t_convert CONVERTS[MAX_CONVERT_OPT] = {
	(t_convert){'c', &convert_c},
	(t_convert){'s', &convert_s},
	(t_convert){'p', &convert_p},
	(t_convert){'d', &convert_d},
	(t_convert){'i', &convert_d},
	(t_convert){'u', &convert_u},
	(t_convert){'x', &convert_x},
	(t_convert){'X', &convert_X},
	(t_convert){'%', &convert_percent},
};


int ft_printf(const char *, ...);


void	ft_putstr_fd_len(const char *s, int fd, ssize_t len);

static unsigned int		uitoa_len(unsigned int nb, int base);
int ft_itoa_ext_buffer(int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer(unsigned int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer_up_10(unsigned int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer_sub_10(unsigned int nbr, char *buffer, int base);

#endif