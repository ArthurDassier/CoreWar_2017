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
#include <stdbool.h>
#include "my.h"
#include "my_getopt.h"
#include "my_fgets.h"
#include "clist.h"
#include "op.h"
#include "define.h"

#define INSTRUCT_SIZE 1

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
	char		**arg;
	enum token_e	*tk_name;
	struct args_s	*arg_tab;
	int		arg_no;
	int		line;
	int		l_size;
};

void add_cmd(struct d_queue *head, int fd);
void add_adressage(struct d_queue *head, int fd);
struct d_queue *lex_file(char *);
header_t *create_header(int, char *, char *);
enum token_e get_arg_type(char *);
int is_line_comment(char *);
int is_header(char *);
int is_label(char *);
int is_arg(char *);
int is_mnemonic(char *);
int count_arg(char *);
void set_mem(struct token *);
void *file_error(char *);
void error_invalid_instruct(char *, int);
void malloc_error(void);

#endif
