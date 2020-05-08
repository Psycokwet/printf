BONUS		=	bonus
NAME		=	scarboni_tester
LIBFT		=	libftprintf.a

SRC_PATH		= ./
OBJ_PATH		= bin/
LIBFT_PATH		= ./../ft_printf/
## No need for a \ on the last line
SRC_FILES	=		main.c

SRCBONUS_FILES	=	main_bonus.c

OBJ_FILES 		= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names
OBJBONUS_FILES	=	$(SRCBONUS_FILES:.c=.o) 					## get all .o names from .c names

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRCBONUS 	= $(addprefix $(SRC_PATH), $(SRCBONUS_FILES))
OBJBONUS 	= $(addprefix $(OBJ_PATH), $(OBJBONUS_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic 		## '+=' allow to keep default flags.

LDFLAGS		=	-L$(LIBFT_PATH) -l:$(LIBFT)		

RM			= 	rm -f

all	: $(NAME) $(BONUS)

test :
		echo $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
		$(CC) -o $@ -c $<

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH) all

$(NAME)		: 	$(OBJ) $(LIBFT)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

$(BONUS)	:	$(OBJBONUS) $(LIBFT)
		$(CC) -o $(NAME) $(OBJBONUS) $(CFLAGS) $(LDFLAGS)
		
clean	:									## delete all .o
		$(RM) $(OBJ) $(OBJBONUS)
		$(MAKE) -C $(LIBFT_PATH) clean	

fclean	:	clean							## clean + delete executable
		$(RM) $(BONUS) $(NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean					

re		:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY	: all bonus clean fclean re
## voir dependances plus tard 
