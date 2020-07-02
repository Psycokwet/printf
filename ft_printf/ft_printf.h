/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:39:42 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 17:26:56 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF


#include <stdio.h>


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"



# define EXIT_CODE_END_FOUND	2
# define EXIT_CODE_FOUND		1
# define EXIT_CODE_NOT_FOUND	0



# define MAX_NBR_LENGTH	    	30
typedef struct		s_data
{
	int				fd;
	int				cursor;
	int				padding_c;
    size_t			len;
	int				written_count;
	const char		*format_s;
	char			nbr_buffer[MAX_NBR_LENGTH];
	int				precision;/*0 si pas précisé valeur. Voir negatives mieux parce que ps clair la
		An optional precision, in the form of a period (".")  followed by an optional decimal digit string.  Instead of a decimal digit string  one  may  write  "*"  or
       "*m$"  (for  some  decimal  integer m) to specify that the precision is given in the next argument, or in the m-th argument, respectively, which must be of type
       int.  If the precision is given as just ".", the precision is taken to be zero.  A negative precision is taken as if the precision were omitted.  This gives the
       minimum  number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the radix character for a, A, e, E, f, and F con‐
       versions, the maximum number of significant digits for g and G conversions, or the maximum number of characters to be printed from a string for s and S  conver‐
       sions.*/

	int				field_width;   /*  
	   An optional decimal digit string (with nonzero first digit) specifying a minimum field width.  If the converted value has fewer characters than the field width,
       it  will be padded with spaces on the left (or right, if the left-adjustment flag has been given).  Instead of a decimal digit string one may write "*" or "*m$"
       (for some decimal integer m) to specify that the field width is given in the next argument, or in the m-th argument, respectively, which must be of type int.  A
       negative field width is taken as a "-" flag followed by a positive field width.  In no case does a nonexistent or small field width cause truncation of a field;
       if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.*/
	unsigned int	active_flags;
    va_list			list;
	char			*value_s;
	void			*value_p;
	int				value_i;
	unsigned int	value_ui;
}					t_data;

typedef struct		s_str
{
	char			*str;
	size_t			size;
}					t_str;


# define MAX_FLAG_OPT	    	4

typedef struct		s_flag
{
	t_str 			code;
	unsigned int	override_flags;
	void			(*prepare_flag)(t_data *);
}					t_flag;

# define FT_PF_FLAG_WRITE		(1u << 0)
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
	(t_flag){(t_str){"-", 1u}, FT_PF_FLAG_ZERO, &prepare_flag_less},
	(t_flag){(t_str){"0", 1u}, FT_PF_NO_FLAG, &prepare_flag_0},
	(t_flag){(t_str){".", 1u}, FT_PF_NO_FLAG, &prepare_flag_precision},
	(t_flag){(t_str){"*", 1u}, FT_PF_NO_FLAG, &prepare_flag_wild_card},
};



unsigned int		uitoa_len(unsigned int nb, int base);
int ft_itoa_ext_buffer(int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer(unsigned int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer_up_10(unsigned int nbr, char *buffer, int base, int faux_chiffre);
int ft_uitoa_ext_buffer_sub_10(unsigned int nbr, char *buffer, int base);





# define MAX_CONVERT_OPT		9
typedef struct		s_convert
{
	t_str 			code;
	int				(*print)(t_data *);
}					t_convert;

//converts :

int convert_c(t_data *datas);
int convert_s(t_data *datas);
int convert_p(t_data *datas);
int convert_d(t_data *datas);
int convert_u(t_data *datas);
int convert_x(t_data *datas);
int convert_up_x(t_data *datas);
int convert_percent(t_data *datas);

static const t_convert CONVERTS[MAX_CONVERT_OPT] = {
	(t_convert){(t_str){"c", 1u}, &convert_c},
	(t_convert){(t_str){"s", 1u}, &convert_s},
	(t_convert){(t_str){"p", 1u}, &convert_p},
	(t_convert){(t_str){"d", 1u}, &convert_d},
	(t_convert){(t_str){"i", 1u}, &convert_d},
	(t_convert){(t_str){"u", 1u}, &convert_u},
	(t_convert){(t_str){"x", 1u}, &convert_x},
	(t_convert){(t_str){"X", 1u}, &convert_up_x},
	(t_convert){(t_str){"%", 1u}, &convert_percent},
};

int ft_printf(const char *, ...);

void set_precision_or_fieldwith(t_data *datas, const int value);
void	ft_putstr_fd_len(const char *s, int fd, ssize_t len);


int set_undefined(const char *str_start, t_data *datas);
int set_convert(const char *str_start, t_data *datas);
int set_value(const char *str_start, t_data *datas);
int set_flag(const char *str_start, t_data *datas);

# define MAX_COMMAND		4
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


void set_padding_c(t_data *datas);
void set_s_len(t_data *datas);

typedef struct		s_write
{
	unsigned int 	flags_concerned;
	unsigned int 	flags_awaited;
	int				(*write)(t_data *);
}					t_write;

# define MAX_WRITTER_S		3
int write_padding(t_data *datas);
int write_s(t_data *datas);

static const t_write WRITER_S[MAX_WRITTER_S] = {
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, &write_padding},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_s},
	(t_write){FT_PF_FLAG_FIELD_WIDTH | FT_PF_FLAG_LESS, FT_PF_FLAG_FIELD_WIDTH, &write_padding},
};

# define MAX_WRITTER_P		1
int    write_p(t_data *datas);

static const t_write WRITER_P[MAX_WRITTER_P] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_p},
};

# define MAX_WRITTER_D		2
int set_d_len(t_data *datas);
int    write_d(t_data *datas);
static const t_write WRITER_D[MAX_WRITTER_D] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &set_d_len},
};

# define MAX_WRITTER_U		2
int set_u_len(t_data *datas);
static const t_write WRITER_U[MAX_WRITTER_U] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &set_u_len},
};
# define MAX_WRITTER_X		2
int set_x_len(t_data *datas);
static const t_write WRITER_X[MAX_WRITTER_X] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &set_x_len},
};

# define MAX_WRITTER_UP_X	2
int set_up_x_len(t_data *datas);
static const t_write WRITER_UP_X[MAX_WRITTER_UP_X] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_d},
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &set_up_x_len},
};


# define MAX_WRITTER_C		1
int    write_c(t_data *datas);
static const t_write WRITER_C[MAX_WRITTER_C] = {
	(t_write){FT_PF_FLAG_WRITE, FT_PF_FLAG_WRITE, &write_c},
};

typedef struct		s_setter
{
	void				(*setter)(t_data *);
}					t_setter;

# define MAX_SETTER_S		3
void set_padding_c(t_data *datas);
void set_s_len(t_data *datas);
void set_value_s(t_data *datas);

static const t_setter SETTER_S[MAX_SETTER_S] = {
	(t_setter){&set_padding_c},
	(t_setter){&set_s_len},
	(t_setter){&set_value_s},
};

# define MAX_SETTER_P		2
void set_p_len(t_data *datas);
void set_value_p(t_data *datas);
static const t_setter SETTER_P[MAX_SETTER_P] = {
	(t_setter){&set_p_len},
	(t_setter){&set_value_p},
};

# define MAX_SETTER_D		1
void set_value_d(t_data *datas);
static const t_setter SETTER_D[MAX_SETTER_D] = {
	(t_setter){&set_value_d},
};

# define MAX_SETTER_U		1
void set_value_u(t_data *datas);
static const t_setter SETTER_U[MAX_SETTER_U] = {
	(t_setter){&set_value_u},
};

# define MAX_SETTER_PERCENT		1
void set_value_percent(t_data *datas);
static const t_setter SETTER_PERCENT[MAX_SETTER_PERCENT] = {
	(t_setter){&set_value_percent},
};

# define MAX_SETTER_C			1
void set_value_c(t_data *datas);
static const t_setter SETTER_C[MAX_SETTER_C] = {
	(t_setter){&set_value_c},
};
#endif
