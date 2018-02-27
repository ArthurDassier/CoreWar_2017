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
	if ((vm->memory = malloc(sizeof(char) * size)) == NULL)
		return (-1);
	vm->memory_end = vm->memory + size;
	vm->head = vm->memory;
	vm->tail = vm->memory;
	vm->size = size;
	vm->count = 0;
	return (0);
}

void memory_put(circular_memory *vm, char data)
{
	*vm->tail = data;
	++vm->tail;
	if (vm->tail == vm->memory_end)
		vm->tail = vm->memory;
	if (is_memory_full(vm) == FULL) {
		if ((vm->head + 1) == vm->memory_end)
			vm->head = vm->memory;
		else
			++vm->head;
	} else
		++vm->count;
}

void memory_pop(circular_memory *vm)
{
	++vm->memory;
	--vm->count;
}

void memory_free(circular_memory *vm)
{
	free(vm->memory);
}

int is_memory_full(circular_memory *vm)
{
	if (vm->count == vm->size)
		return (FULL);
	return (NOT_FULL);
}
