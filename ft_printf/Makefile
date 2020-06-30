BONUS		=	bonus
NAME		=	libftprintf.a	
LIBFT		=	libft/libft.a

SRC_PATH		= ./
OBJ_PATH		= bin/
LIBFT_PATH		= libft/
## No need for a \ on the last line
HEADERS_FILES	=	ft_printf.h
SRC_FILES		=	ft_printf.c			\
					ft_convert.c		\
					ft_commands.c		\
					ft_putstr_fd_len.c

SRCBONUS_FILES	=	ft_bonus.c

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

LDFLAG		=	-l$(LIBFT)		

RM			= 	rm -f

all	: $(NAME)

test :
	echo $(SRC_FILES)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS_FILES)
		mkdir -p $(OBJ_PATH)
		$(CC) -o $@ -c $< $(CFLAGS)

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH) $(BONUS)
		cp $(LIBFT) ./$(NAME)

$(NAME)		: 	$(OBJ) $(LIBFT) 
		echo ar -src $(NAME) $(OBJ) 
		ar -src $(NAME) $(OBJ) 

$(BONUS)	:
		$(MAKE) WITH_BONUS=1 all
		
clean	:									## delete all .o
		$(RM) $(OBJ) $(OBJBONUS)
		$(MAKE) -C $(LIBFT_PATH) clean	

fclean	:	clean							## clean + delete executable
		$(RM) $(NAMETEST) $(NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean					

re		:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY	: all bonus clean fclean re
## voir dependances plus tard 