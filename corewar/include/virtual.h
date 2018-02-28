/*
** EPITECH PROJECT, 2017
** virtual.h
** File description:
** Arthur
*/

#ifndef VIRTUAL_H_
#define VIRTUAL_H_

#include "my.h"

typedef struct circular_memory
{
	char	*memory;
	char	*memory_head;
	char	*memory_end;
	char	*pars;
	int	count;
	int	size;
} circular_memory;

void fill_arg(arguments *argv, char *flag, char *parameter);
arguments *init_vm(char **av, arguments *argv);
int cycles(circular_memory *vm, champions **champ, arguments *argv);

int memory_init(circular_memory *vm, int size);
void memory_put(circular_memory *vm, char data, int adr);
void memory_memset(char *memory, int size);
int adr_acc(int adr);
int set_flag(int adr);

#endif
