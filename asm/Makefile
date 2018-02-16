##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

LFLAGS= -L./lib -lmy

NAME=	asm

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all
	make -C lib/my re

.PHONY: clean fclean re
