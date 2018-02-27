##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc -g3

FLAGS=	-g3 -Wall -Wextra -I./include

LFLAGS= -L./lib -lmy -lclist -lmy_getopt -lmy_fgets

NAME=	asm

SRC_DIR=	$(realpath ./srcs/)

SRC=		$(SRC_DIR)/my_main.c		\
			$(SRC_DIR)/instruction.c	\
			$(SRC_DIR)/adressage.c	\
			$(SRC_DIR)/bits.c	\
			$(SRC_DIR)/op.c		\
			$(SRC_DIR)/lex.c                                          \
			$(SRC_DIR)/mem.c                                          \
			$(SRC_DIR)/string.c                                       \
			$(SRC_DIR)/string2.c                                      \
			$(SRC_DIR)/string3.c                                      \
			$(SRC_DIR)/header.c                                       \
			$(SRC_DIR)/error.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	make -C lib/my
	make -C lib/clist
	make -C lib/my_getopt
	make -C lib/my_fgets
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C lib/my clean
	make -C lib/clist clean
	make -C lib/my_getopt clean
	make -C lib/my_fgets clean
	@rm -rf $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/clist fclean
	make -C lib/my_getopt fclean
	make -C lib/my_fgets fclean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all
	make -C lib/my re
	make -C lib/clist re
	make -C lib/my_getopt re
	make -C lib/my_fgets re

.PHONY: clean fclean re
