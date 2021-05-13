##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC		=	lib/my/my_atoi.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strlen.c	\
			src/find_bsq.c		\
			src/init_bsq.c		\
			src/main.c		\
			src/draw_bsq.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) -g3 -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
