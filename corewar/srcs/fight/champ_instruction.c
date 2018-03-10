/*
** EPITECH PROJECT, 2017
** champ_instruction.c
** File description:
** champ_instructions_c_
*/

#include "virtual.h"

int inst_cycle(int ins)
{
	return (op_tab[ins - 1].nbr_cycles);
}

int is_adr(int ins)
{
	if (ins == 2 || ins == 3)
		return (1);
	else if (ins >= 6 && ins <= 8)
		return (1);
	if (ins == 10 || ins == 11)
		return (1);
	else if (ins == 13 || ins == 14)
		return (1);
	return (0);
}

int champ_instru(champions *champ)
{
	if (champ->cycle != 0)
		return (0);
	while (champ->inst == 0) {
		champ->inst = champ_instru(champ);
		if (is_adr(champ->inst) == 1)
			if ((champ->types = champ_params_types(champ,
					op_tab[champ->inst - 1].type[MAX_ARGS_NUMBER])) == -1)
				champ->inst = rec_instru(champ);
	}
	champ->cycle = inst_cycle(champ->inst);
	return (0);
}

int exec_instruc(champions *champ, circular_memory *vm,
		int (*exec_tab[16])(circular_memory *vm, champions *champ))
{
	(void) vm;
	if (champ->cycle != 0)
		return (0);
	exec_tab[champ->inst - 1](vm, champ);
	return (0);
}

int champ_loop(champions **champ, circular_memory *vm)
{
	static int	(*exec_tab[16])(circular_memory *vm, champions *champ);
	int		i = 0;

	init_exec_instru_tab(exec_tab);
	while (champ[i] != NULL) {
		champ_instru(champ[i]);
		exec_instruc(champ[i++], vm, exec_tab);
		--champ[i]->cycle;
	}
	return (0);
}
