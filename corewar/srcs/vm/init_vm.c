/*
** EPITECH PROJECT, 2017
** init_vm.c
** File description:
** init_vm_c_
*/

#include "my.h"
#include <stdio.h>

int memory_init(circular_memory *vm, champions **champ, arg_champ *av_list,
		int size)
{
	int		i = 0;

	if ((vm->memory = malloc(sizeof(char) * (size + 1))) == NULL)
		return (-1);
	vm->memory_end = vm->memory + size;
	vm->memory_head = vm->memory;
	while (champ[i] != NULL)
		champ[i++]->pars = vm->memory;
	vm->size = size;
	memory_memset(vm->memory, size);
	return (0);
}

void memory_put(circular_memory *vm, champions *champ, char data, int adr)
{
	int		flag = 0;
	int		flag2 = 0;

	if (adr > 0)
		flag2 = 1;
	flag = set_flag(adr);
	while (adr != 0) {
		if (champ->pars == vm->memory_end)
			champ->pars = vm->memory_head;
		else if (champ->pars == vm->memory_head - flag2)
			champ->pars = vm->memory_end;
		champ->pars += flag;
		adr = adr_acc(adr);
	}
	*champ->pars = data;
}

int adr_acc(int adr)
{
	if (adr > 0)
		--adr;
	else
		++adr;
	return (adr);
}
int set_flag(int adr)
{
	int	flag = 0;

	if (adr > 0)
		flag = 1;
	else
		flag = -1;
	return (flag);
}

void memory_memset(char *memory, int size)
{
	int	i = 0;

	while (i != size)
		memory[i++] = '0';
	memory[i] = '\0';
}
