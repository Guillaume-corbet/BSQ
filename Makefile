##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	./source/main.c		\
			./source/stock.c

OBJ		=	$(SRC:.c=.o)

NAME	=	bsq

all:	clean fclean $(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		gcc -g3 -o $(NAME) $(SRC) -Llib/my/. -lmy

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean $(NAME)

auteur:
		echo $(USER) > auteur
