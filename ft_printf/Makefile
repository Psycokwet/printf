NAME		=	libftprintf.a
BONUS		=	bonus	
MAKE_LIBFT	=	makelibft
LIBFT		=	libft
LIBFT_AR	=	libft/libft.a

SRC_PATH			= ./
WRITERS_PATH		= writers/
SETTERS_PATH		= setters/
CONVERTS_PATH		= converts/
PREPARE_FLAGS_PATH	= prepare_flags/
NBR_MANAGEMENT_PATH	= nbr_management/
COMMANDS_PATH		= commands/
OBJ_PATH			= bin/
LIBFT_PATH			= libft/

OBJ_PATHS_INIT			=	$(addprefix $(OBJ_PATH),$(SETTERS_PATH) 		\
													$(WRITERS_PATH) 		\
													$(CONVERTS_PATH)		\
													$(PREPARE_FLAGS_PATH)	\
													$(NBR_MANAGEMENT_PATH)	\
													$(COMMANDS_PATH))
OBJ_PATHS_INIT			+= 	$(OBJ_PATH)
## No need for a \ on the last line
HEADERS_FILES				=	ft_printf.h
SRC_FILES					=	ft_printf.c	 					\
								set_width_precision_u.c			\
								set_width_precision_x_up_x.c	\
								write_diese_x_up_x.c	 		\
								write_padding.c write_str.c	 	\
								write_ui_value_in_buffer.c	 	\
								write_uix_value_in_buffer.c
CONVERTS_SRC_FILES			=	convert.c	 					\
								convert_c.c						\
								convert_d.c						\
								convert_e.c						\
								convert_f.c						\
								convert_g.c						\
								convert_n.c						\
								convert_p.c						\
								convert_percent.c				\
								convert_s.c						\
								convert_u.c						\
								convert_up_x.c					\
								convert_x.c
WRITERS_SRC_FILES			=	write_c.c						\
								write_d_in_buffer.c				\
								write_diese_up_x.c				\
								write_diese_x.c					\
								write_nbr_buffer.c				\
								write_one_space.c				\
								write_p.c						\
								write_p_in_buffer.c				\
								write_padding_d.c				\
								write_padding_s.c				\
								write_precision_d.c				\
								write_s.c						\
								write_u_in_buffer.c				\
								write_up_x_in_buffer.c			\
								write_value_i_sign.c			\
								write_x_in_buffer.c				\
								writer_no_writer.c				\
								writer_undefined.c
SETTERS_SRC_FILES			=	set_correct_diese.c				\
								set_diese_cost.c				\
								set_padding_c.c					\
								set_s_len.c						\
								set_value_c.c					\
								set_value_d.c					\
								set_value_p.c					\
								set_value_percent.c				\
								set_value_s.c					\
								set_value_u.c					\
								setter_outer_int_n.c			\
								setter_undefined.c
PREPARE_FLAGS_SRC_FILES		=	prepare_flag_0.c				\
								prepare_flag_h.c				\
								prepare_flag_l.c				\
								prepare_flag_ll.c				\
								prepare_flag_precision.c		\
								prepare_flag_wild_card.c		\
								prepare_flag_diese.c			\
								prepare_flag_hh.c				\
								prepare_flag_less.c				\
								prepare_flag_plus.c				\
								prepare_flag_space.c			\
								set_precision_or_fieldwith.c
NBR_MANAGEMENT_SRC_FILES	=	ft_itoa_ext_buffer.c			\
								ft_uitoa_ext_buffer.c			\
								ft_uitoa_ext_buffer_sub_10.c	\
								ft_uitoa_ext_buffer_up_10.c		\
								strlen_from_int.c				\
								uitoa_len.c
COMMANDS_SRC_FILES			=	set_convert.c					\
								set_flag.c						\
								set_undefined.c					\
								set_value.c

SRC_FILES	+=	$(addprefix $(CONVERTS_PATH), 		$(CONVERTS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(SETTERS_PATH), 		$(SETTERS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(WRITERS_PATH), 		$(WRITERS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(PREPARE_FLAGS_PATH), 	$(PREPARE_FLAGS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(NBR_MANAGEMENT_PATH), $(NBR_MANAGEMENT_SRC_FILES))
SRC_FILES	+=	$(addprefix $(COMMANDS_PATH), 		$(COMMANDS_SRC_FILES))

OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names

OBJ_FILES = $(OBJREGULAR_FILES)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic 		## '+=' allow to keep default flags.

RM			= 	rm -f

OS			= $(shell uname)
ifeq ($(OS), Linux)
	CFLAGS	+= -DLINUX
endif

all					:	 $(OBJ_PATHS_INIT) $(MAKE_LIBFT) $(NAME)

$(LIBFT_PATH)  		:
	git clone https://github.com/Psycokwet/libft.git $(LIBFT_PATH)

$(MAKE_LIBFT)		: $(LIBFT_PATH)
	$(MAKE) -C $(LIBFT_PATH)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@  

$(NAME)			: 	$(OBJ)  $(LIBFT_AR)
	cp $(LIBFT_AR) ./$(NAME)
	ar -src $(NAME) $(OBJ) 

$(BONUS)		: all
		
clean_local		:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)

clean			:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)
	$(MAKE) -C $(LIBFT_PATH) clean	

fclean			:	clean_local							## clean + delete executable
	$(RM) $(NAMETEST) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean					

re				:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY			:	all bonus clean fclean re
## voir dependances plus tard 