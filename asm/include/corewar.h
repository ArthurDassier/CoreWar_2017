/*
** EPITECH PROJECT, 2017
** corewar.h
** File description:
** corewar header file
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "my.h"
#include "my_getopt.h"
#include "my_fgets.h"
#include "clist.h"
#include "op.h"
#include "define.h"

enum type_e {
	L,
	I
};

enum token_e {
	REG,
	DRT,
	IND,
	LAB
};

struct	args_s {
	char	*args;
	enum	token_e tk_name;
};

union	endian {
	char	byte[4];
	int	val;
};

struct token
{
	enum type_e	tk_val;
	char		*mnemo;
	struct args_s	*arg_tab;
	int		arg_no;
	int		line;
};

struct d_queue	*lex_file(char *);
int		is_line_comment(char *);
void		*file_error(char *);
void		malloc_error(void);
void		add_cmd(struct d_queue *head, int fd);
void		add_adressage(struct d_queue *head, int fd);
void		add_param(struct d_queue *head, int fd);
int		my_compute_power_rec(int nb, int p);
int		my_getnbr_base(char const *str, char const *base);
void		print_bits(struct token *token, int fd, int i);
void		parser(struct d_queue *head, int fd);
void		registers(struct token *token, int fd, int i);
void		directs(struct token *token, int fd, int i);
void		indirects(struct token *token, int fd, int i);
void		swap_endian(union endian *result);

#endif