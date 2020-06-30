BONUS		=	bonus
NAME		=	scarboni_tester
PRINTF		=	libftprintf.a
MAKE_PRINTF = 	make_printf

SRC_PATH		= ./
OBJ_PATH		= bin/
PRINTF_PATH		= ./../ft_printf/
## No need for a \ on the last line
SRC_FILES		=	main.c

SRCBONUS_FILES	=	main_bonus.c

OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names
OBJBONUS_FILES		=	$(SRCBONUS_FILES:.c=.o) 					## get all .o names from .c names

ifdef WITH_BONUS
OBJ_FILES = $(OBJBONUS_FILES)
PRINTF_MAKE_COMMAND		=	$(BONUS)
else
OBJ_FILES = $(OBJREGULAR_FILES)
PRINTF_MAKE_COMMAND		=	all
endif

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRCBONUS 	= $(addprefix $(SRC_PATH), $(SRCBONUS_FILES))
OBJBONUS 	= $(addprefix $(OBJ_PATH), $(OBJBONUS_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic 		## '+=' allow to keep default flags.

LDFLAGS		=	-L$(PRINTF_PATH) -l:$(PRINTF)		

RM			= 	rm -f

all	: $(MAKE_PRINTF) $(NAME)

test :
	echo $(CC) -o $(NAME) $(OBJ)  $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
		$(CC) -o $@ -c $< $(CFLAGS)

$(MAKE_PRINTF):
		$(MAKE) -C $(PRINTF_PATH) $(PRINTF_MAKE_COMMAND)

$(NAME)		: 	$(OBJ) $(PRINTF_PATH)$(PRINTF)
		$(MAKE) -C $(PRINTF_PATH) $(PRINTF_MAKE_COMMAND)
		$(CC) -o $(NAME) $(OBJ)  $(LDFLAGS)

$(BONUS)	:
	$(MAKE) WITH_BONUS=1 all
		
clean_local		:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)

clean	:									## delete all .o
		$(RM) $(OBJ) $(OBJBONUS)
		$(MAKE) -C $(PRINTF_PATH) clean	

fclean	:	clean_local							## clean + delete executable
		$(RM) $(BONUS) $(NAME)
		$(MAKE) -C $(PRINTF_PATH) fclean					

re		:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY	: all bonus clean fclean re
## voir dependances plus tard 
