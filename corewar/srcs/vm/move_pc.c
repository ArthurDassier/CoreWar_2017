/*
** EPITECH PROJECT, 2017
** move_pc.c
** File description:
** move_pc_c
*/

#include "virtual.h"

void move_pc(circular_memory *vm, champions *champ, int nb)
{
	int flag = 0;

	if (nb > 0)
		flag = 1;
	else
		flag = -1;
	while (nb != 0) {
		if (champ->PC == vm->memory_end)
			champ->PC = vm->memory_head;
		else if (champ->PC == vm->memory_head)
			champ->PC = vm->memory_end;
	}
}
