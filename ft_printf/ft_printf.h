/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/06/29 14:41:58 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF


#include <stdio.h>


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

# define MAX_NBR_LENGTH	    	30
typedef struct		s_data
{
	int				fd;
	int				cursor;
	int				written_count;
	const char		*format_s;
	char			nbr_buffer[MAX_NBR_LENGTH];
	int				precision;/*0 si pas précisé valeur. Voir negatives mieux parce que ps clair la
		An optional precision, in the form of a period ('.')  followed by an optional decimal digit string.  Instead of a decimal digit string  one  may  write  "*"  or
       "*m$"  (for  some  decimal  integer m) to specify that the precision is given in the next argument, or in the m-th argument, respectively, which must be of type
       int.  If the precision is given as just '.', the precision is taken to be zero.  A negative precision is taken as if the precision were omitted.  This gives the
       minimum  number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the radix character for a, A, e, E, f, and F con‐
       versions, the maximum number of significant digits for g and G conversions, or the maximum number of characters to be printed from a string for s and S  conver‐
       sions.*/

	int				field_width;   /*  
	   An optional decimal digit string (with nonzero first digit) specifying a minimum field width.  If the converted value has fewer characters than the field width,
       it  will be padded with spaces on the left (or right, if the left-adjustment flag has been given).  Instead of a decimal digit string one may write "*" or "*m$"
       (for some decimal integer m) to specify that the field width is given in the next argument, or in the m-th argument, respectively, which must be of type int.  A
       negative field width is taken as a '-' flag followed by a positive field width.  In no case does a nonexistent or small field width cause truncation of a field;
       if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.*/
	unsigned int	active_flags;
    va_list			list;
}					t_data;

# define MAX_FLAG_OPT	    	4

typedef struct		s_flag
{
	int				flag;
	unsigned int	override_flags;
	void			(*prepare_flag)(t_data *);
}					t_flag;

# define FT_PF_FLAG_ZERO		(1u << 1)
# define FT_PF_FLAG_LESS		(1u << 2)
# define FT_PF_FLAG_FIELD_WIDTH	(1u << 3)
# define FT_PF_FLAG_PRECISION	(1u << 4)
# define FT_PF_NO_FLAG			0

void prepare_flag_less(t_data *datas);
void prepare_flag_0(t_data *datas);
void prepare_flag_precision(t_data *datas);
void prepare_flag_wild_card(t_data *datas);

static const t_flag FLAGS[MAX_FLAG_OPT] = {
	(t_flag){'-', FT_PF_FLAG_ZERO, &prepare_flag_less},
	(t_flag){'0', FT_PF_NO_FLAG, &prepare_flag_0},
	(t_flag){'.', FT_PF_NO_FLAG, &prepare_flag_precision},
	(t_flag){'*', FT_PF_NO_FLAG, &prepare_flag_wild_card},
};



unsigned int		uitoa_len(unsigned int nb, int base);
int ft_itoa_ext_buffer(int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer(unsigned int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer_up_10(unsigned int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer_sub_10(unsigned int nbr, char *buffer, int base);





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
void convert_up_x(t_data *datas);
void convert_percent(t_data *datas);

static const t_convert CONVERTS[MAX_CONVERT_OPT] = {
	(t_convert){'c', &convert_c},
	(t_convert){'s', &convert_s},
	(t_convert){'p', &convert_p},
	(t_convert){'d', &convert_d},
	(t_convert){'i', &convert_d},
	(t_convert){'u', &convert_u},
	(t_convert){'x', &convert_x},
	(t_convert){'X', &convert_up_x},
	(t_convert){'%', &convert_percent},
};


int ft_printf(const char *, ...);


void	ft_putstr_fd_len(const char *s, int fd, ssize_t len);


#endif