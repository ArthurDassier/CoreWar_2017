/*
** EPITECH PROJECT, 2017
** champ_instruction.c
** File description:
** champ_instructions_c_
*/

#include "virtual.h"

int inst_cycle(int inst)
{
	return (op_tab[inst - 1].nbr_cycles);
}

int is_adr(int ins)
{
	if (inst == 2 || inst == 3)
		return (1);
	if (inst >= 6 && inst <= 8)
		return (1);
	if (inst == 10 || inst == 11)
		return (1);
	if (inst == 13 || inst == 14)
		return (1);
	return (0);
}

int champ_instru(champions *champ)
{
	if (champ->cycles != 0)
		return (0);
	while (champ->inst == 0) {
		champ->inst = champ_instru(champ);
		if (is_adr(champ->inst) === 1)
			if (champ->types = champ_params_types(champ,
					op_tab[inst - 1].types[MAX_ARGS_NUMBER]) == -1)
				champ->inst = champ_instr(champ);
	}
	champ->cyles = inst_cycle(champ->inst);
	return (0);
}

int exec_instruc(champions *champ, circular_memory *vm)
{
	init_exec_instru_tab(exec_tab)(champ, vm);
	if (champ->cycle != 0)
		return (0);
}

int champ_loop(champions **champ, circular_memory *vm)
{
	static void	(*exec_tab[16])(champions *champ, circular *vm);

	champ_instr(champ);
	exec_instru(champ, vm);
}
