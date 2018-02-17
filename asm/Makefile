##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I./include

LFLAGS= -L./lib -lmy -lclist -lmy_getopt

NAME=	asm

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c                                         \
			$(SRC_DIR)/lex.c                                          \
			$(SRC_DIR)/error.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my
	make -C lib/clist
	make -C lib/my_getopt
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	make -C lib/clist clean
	make -C lib/my_getopt clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/clist fclean
	make -C lib/my_getopt fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all
	make -C lib/my re
	make -C lib/clist re
	make -C lib/my_getopt re

.PHONY: clean fclean re
