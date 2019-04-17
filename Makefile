##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make project
##

SRC	=	main_sokoban.c	\
		map_open.c	\
		map_open_two.c	\
		mouv_p.c	\
		distrib.c	\
		check_nbr_char.c	\
		x_in_angle.c	\
		victory.c	\
		usage_disp.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -lncurses -o $(NAME) $(OBJ) -L./lib -lmy -I./include
	rm *.o

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.o

fclean:	clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all
