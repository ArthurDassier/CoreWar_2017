/*
** EPITECH PROJECT, 2017
** exec_instructions.c
** File description:
** exec_instructions_c_
*/

#include "virtual.h"

int recup_instruction(circular_memory *vm, champions *champ)
{
	static int	cycl = champ->list->nb_cycles;
	int		inst = 0;

	if (cycle != 0) {
		--cycles;
		return (1);
	}
	inst = champ->list->mnemonique / (16 * 16) % 16;
	inst = inst * 10 + champ->list->mnemonique % 16;
}

void init_exec_instru_tab(void (**exec_instru_tab)(circular_memory *vm,
			champions *champ))
{

}

void do_instruction(champions *champ)
{

}
