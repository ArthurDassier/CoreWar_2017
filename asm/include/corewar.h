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
#include "clist.h"

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

struct token
{
	enum type_e	tk_val;
	char		*mnemo;
	char		**arg;
	enum token_e	*tk_name;
	int		arg_no;
	int		line;
};

#endif
