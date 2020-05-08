BONUS		=	bonus
NAME		=	libftprintf.a	
LIBFT		=	libft/libft.a

SRC_PATH		= ./
OBJ_PATH		= bin/
LIBFT_PATH		= libft/
## No need for a \ on the last line
SRC_FILES	=		ft_printf.c

SRCBONUS_FILES	=	ft_bonus.c

OBJ_FILES 		= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names
OBJBONUS_FILES	=	$(SRCBONUS_FILES:.c=.o) 					## get all .o names from .c names

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRCBONUS 	= $(addprefix $(SRC_PATH), $(SRCBONUS_FILES))
OBJBONUS 	= $(addprefix $(OBJ_PATH), $(OBJBONUS_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic 		## '+=' allow to keep default flags.

LDFLAG		=	-l$(LIBFT)		

RM			= 	rm -f

all	: $(BONUS)

test :
	echo $(OBJ) $(LDFLAG)  $(LIBFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
		$(CC) -o $@ -c $<

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH) all
		cp $(LIBFT) ./$(NAME)

$(NAME)		: 	$(OBJ) $(LIBFT)
		ar -src $(NAME) $(OBJ) 

$(BONUS)	: $(NAME) $(OBJBONUS)
		ar -src $(NAME) $(OBJBONUS)
		
clean	:									## delete all .o
		$(RM) $(OBJ) $(OBJBONUS)
		$(MAKE) -C $(LIBFT_PATH) clean	

fclean	:	clean							## clean + delete executable
		$(RM) $(NAMETEST) $(NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean					

re		:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY	: all bonus clean fclean re
## voir dependances plus tard 
