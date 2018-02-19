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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
void		add_cmd(struct d_queue *head);

#endif