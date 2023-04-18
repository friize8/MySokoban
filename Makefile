##
## EPITECH PROJECT, 2021
## B-PSU-200-STG-2-1-mysokoban-yanis.ktab
## File description:
## Makefile
##

SRC	=	./lib/my_strlen.c \
		./lib/my_putstr.c \
		./lib/my_str_to_word_array.c \
		./src/main.c \
		./src/cat.c	\
		./src/player.c \
		./src/move.c

CFLAGS = -g -s -Wextra -Wall -Wpedantic

OBJ =    $(SRC:.c=.o)

NAME =	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
