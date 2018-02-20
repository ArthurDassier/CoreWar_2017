##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc

FLAGS=	-Wall -Wextra -Werror -I../asm/include

##LFLAGS= -L./lib -lmy

NAME=	corewar

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c			\
		$(SRC_DIR)/args_errors/argc_err.c	\
		$(SRC_DIR)/args_errors/err_gs_acav.c	\

OBJ=		$(SRC:.c=.o)

all:		$(NAME) clean

$(NAME):	$(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) ##$(LFLAGS)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:		clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
