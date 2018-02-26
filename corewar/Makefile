##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	srcs/main.c						\
		srcs/args_errors/error_gest_controler.c			\
		srcs/args_errors/ac_errors/number_of_ac_errors.c	\
		srcs/args_errors/av_errors/check_for_flags.c		\
		srcs/args_errors/av_errors/dot_cor_errors.c		\
		srcs/args_errors/av_errors/flags_errors.c		\
		srcs/args_errors/av_errors/look_ff_errors.c		\

OBJ	=	$(SRC:.c = .o)

NAME	=	corewar

LIB_DIR	=	./lib

MY.H_DIR	=	./include

CC	=	gcc

C_FLAGS	=	-Wall -Wextra

LIB_FLAG	=	-L$(LIB_DIR) -lmy

INCL_FLAG	=	-I$(MY.H_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(C_FLAGS) $(LIB_FLAG) $(INCL_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
