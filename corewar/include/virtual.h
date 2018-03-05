/*
** EPITECH PROJECT, 2017
** virtual.h
** File description:
** Arthur
*/

#ifndef VIRTUAL_H_
#define VIRTUAL_H_

#include "my.h"

typedef struct arg_champ arg_champ;

typedef struct circular_memory
{
	char	*memory;
	char	*memory_head;
	char	*memory_end;
	char	*pars;
	int	count;
	int	size;
} circular_memory;

struct arg_champ
{
	int		hyp_a;
	int		hyp_n;
	char		*cor;
	arg_champ	*next;
};

arg_champ *put_arg(int ac, char **av);
arg_champ *init_ag_champ(int hyp_a, int hyp_n, char *av);
void insert_begin(arg_champ **first_elem, int hyp_a, int hyp_n, char *av);
void insert_end(arg_champ **first_elem, int hyp_a, int hyp_n, char *av);

int memory_init(circular_memory *vm, int size);
void memory_put(circular_memory *vm, char data, int adr);
void memory_memset(char *memory, int size);
int adr_acc(int adr);
int set_flag(int adr);

#endif
