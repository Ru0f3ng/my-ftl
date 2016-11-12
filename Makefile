CC		= gcc

NAME		= my_ftl

SRC		= aff_menu.c \
		  air_shed.c \
		  container.c \
		  detect.c \
		  fight.c \
		  jump.c \
		  main.c \
		  my_string.c \
		  my_put_nbr.c \
		  my_rand.c \
		  readline.c \
		  system_control.c \
		  system_repair.c \
		  system_main.c

OBJ		= $(SRC:%.c=%.o)

CFLAGS		= -Wall -Wextra -Werror

RM		= rm -f

$(NAME):	$(OBJ)
		$(CC) -I . $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
