BONUS		=	bonus
NAME		=	libftprintf.a	
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
## No need for a \ on the last line
HEADERS_FILES				=	ft_printf.h
SRC_FILES					=	ft_printf.c						\
								ft_commands.c					\
								ft_prepare_flags.c				\
								ft_nbr_management.c				\
								ft_putstr_fd_len.c
CONVERTS_SRC_FILES			=	convert.c	 					\
								convert_c.c						\
								convert_d.c						\
								convert_p.c						\
								convert_percent.c				\
								convert_s.c						\
								convert_u.c						\
								convert_up_x.c					\
								convert_x.c
WRITERS_SRC_FILES			=	set_d_len.c						\
								set_u_len.c						\
								set_up_x_len.c					\
								set_x_len.c						\
								write_c.c						\
								write_d.c						\
								write_padding.c					\
								write_p.c						\
								write_s.c
SETTERS_SRC_FILES			=	set_d_len.c						\
								set_padding_c.c					\
								set_p_len.c						\
								set_s_len.c						\
								set_u_len.c						\
								set_value_c.c					\
								set_value_d.c					\
								set_value_p.c					\
								set_value_percent.c				\
								set_value_s.c					\
								set_value_u.c
PREPARE_FLAGS_SRC_FILES		=	prepare_flag_0.c				\
								prepare_flag_less.c				\
								prepare_flag_precision.c		\
								prepare_flag_wild_card.c		\
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

SRCBONUS_FILES	=	ft_bonus.c

SRC_FILES	+=	$(addprefix $(CONVERTS_PATH), 		$(CONVERTS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(SETTERS_PATH), 		$(SETTERS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(WRITERS_PATH), 		$(WRITERS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(PREPARE_FLAGS_PATH), 	$(PREPARE_FLAGS_SRC_FILES))
SRC_FILES	+=	$(addprefix $(NBR_MANAGEMENT_PATH), $(NBR_MANAGEMENT_SRC_FILES))
SRC_FILES	+=	$(addprefix $(COMMANDS_PATH), 		$(COMMANDS_SRC_FILES))

OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names
OBJBONUS_FILES		=	$(SRCBONUS_FILES:.c=.o) 

ifdef WITH_BONUS
OBJ_FILES = $(OBJREGULAR_FILES) $(OBJBONUS_FILES)
else
OBJ_FILES = $(OBJREGULAR_FILES)
endif

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRCBONUS 	= $(addprefix $(SRC_PATH), $(SRCBONUS_FILES))
OBJBONUS 	= $(addprefix $(OBJ_PATH), $(OBJBONUS_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic 		## '+=' allow to keep default flags.

LDFLAG		=	-l$(LIBFT_AR)		

RM			= 	rm -f

all				:	 $(MAKE_LIBFT) $(NAME)

$(MAKE_LIBFT)	:
	$(MAKE) -C $(LIBFT_PATH) $(BONUS)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)$(SETTERS_PATH)
	mkdir -p $(OBJ_PATH)$(WRITERS_PATH)
	mkdir -p $(OBJ_PATH)$(CONVERTS_PATH)
	mkdir -p $(OBJ_PATH)$(PREPARE_FLAGS_PATH)
	mkdir -p $(OBJ_PATH)$(NBR_MANAGEMENT_PATH)
	mkdir -p $(OBJ_PATH)$(COMMANDS_PATH)
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME)			: 	$(OBJ)  $(LIBFT_AR)
	cp $(LIBFT_AR) ./$(NAME)
	ar -src $(NAME) $(OBJ) 

$(BONUS)		:
	$(MAKE) WITH_BONUS=1 all
		
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