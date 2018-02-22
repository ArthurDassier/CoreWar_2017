##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

CC=		gcc -g3

FLAGS=	-Wall -Wextra -I../asm/include

##LFLAGS= -L./lib -lmy

NAME=	corewar

SRC_DIR=	$(realpath ./srcs/)
SRC=		$(SRC_DIR)/main.c					\
		$(SRC_DIR)/args_errors/error_gest_controler.c		\
		$(SRC_DIR)/args_errors/ac_errors/number_of_ac_errors.c	\
		$(SRC_DIR)/args_errors/av_errors/check_for_flags.c	\
		$(SRC_DIR)/args_errors/av_errors/dot_cor_errors.c	\
		$(SRC_DIR)/args_errors/av_errors/flags_errors.c		\

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
