/*
** EPITECH PROJECT, 2017
** init_registers.c
** File description:
** init_registers_c_
*/

#include "my.h"

int find_register(circular_memory *vm, int regi)
{
	int	i = 0;
	int	j = -1;

	while (++i != regi)
		vm->memory_head += 4;
	regi = *vm->memory_head - 48;
	++vm->memory_head;
	while (++j != 3) {
		regi *= 10;
		regi += *vm->memory_head - 48;
		++vm->memory_head;
	}
	vm->memory_head = vm->memory;
	return (regi);
}
