/*
** EPITECH PROJECT, 2017
** init_vm.c
** File description:
** init_vm_c_
*/

#include "my.h"
#include <stdio.h>

int memory_init(circular_memory *vm, int size)
{
	if ((vm->memory = malloc(sizeof(char) * (size + 1))) == NULL)
		return (-1);
	vm->memory_end = vm->memory + size;
	vm->memory_head = vm->memory;
	vm->pars = vm->memory;
	vm->size = size;
	vm->count = 0;
	return (0);
}

void memory_put(circular_memory *vm, char data, int adr)
{
	int	flag = 0;

	flag = set_flag(adr);
	while (adr != 0) {
		vm->pars += flag;
		if (vm->pars == vm->memory_end)
			vm->pars = vm->memory_head;
		else if (vm->pars == vm->memory_head)
			vm->pars = vm->memory_end;
		adr = adr_acc(adr);
	}
	*vm->pars = data;
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

void memory_memset(circular_memory *vm, int size)
{
	int	i = 0;

	while (i != size)
		vm->memory[i++] = '0';
	vm->memory[i] = '\0';
}
