/*
** EPITECH PROJECT, 2017
** exec_instructions.c
** File description:
** exec_instructions_c_
*/

#include "virtual.h"

static void num_cycle(int i, circular_memory *vm, champions **champ)
{
	struct instructions	*tmp = champ[0]->list;
	int			cycle = 0;
	int			j = 0;

	while (champ[j] != NULL) {
		tmp = champ[j]->list;
		while (tmp->next != NULL) {
			cycle += tmp->nb_cycles;
			if (i > cycle)
				tmp = tmp->next;
			if (i == cycle) {
				recup_instruction(tmp, vm, champ);
				break;
			}
			if (i < cycle)
				break;
			}
		cycle = 0;
		++j;
	}
}

static int cycles(circular_memory *vm, champions **champ)
{
	int	cycle_to_die = CYCLE_TO_DIE;
	int	cycle_delta = CYCLE_DELTA;
	int	i = 0;

	while (cycle_to_die > 0) {
		while (i != cycle_to_die) {
			num_cycle(i, vm, champ);
			++i;
		}
		i = 0;
		cycle_to_die -= cycle_delta;
	}
	return (0);
}

static int recup_instruction(instructions *instr, circular_memory *vm, champions *champ)
{
	int	inst = 0;

	inst = champ->list->mnemonique[0]  % 16;
	inst = inst * 10 + champ->list->mnemonique[1] % 16;
	return (inst);
}

static void init_exec_instru_tab(void (**exec_instru_tab)(instructions *instr,
champions *champ, circular_memory *vm))
{
	exec_instru_tab[0] = &live_instru;
	exec_instru_tab[1] = &ld_instru;
	exec_instru_tab[2] = &st_instru;
	exec_instru_tab[3] = &add_instru;
	exec_instru_tab[4] = &sub_instru;
	exec_instru_tab[5] = &and_instru;
	exec_instru_tab[6] = &or_instru;
	exec_instru_tab[7] = &xor_instru;
	exec_instru_tab[8] = &zjmp_instru;
	exec_instru_tab[9] = &ldi_instru;
	exec_instru_tab[10] = &sti_instru;
	exec_instru_tab[11] = &fork_instru;
	exec_instru_tab[12] = &lld_instru;
	exec_instru_tab[13] = &lldi_instru;
	exec_instru_tab[14] = &lfork_instru;
	exec_instru_tab[15] = &aff_instru;
}

void do_instructions(circular_memory *vm, champions *champ)
{
	static void	(*exec_tab[16])(instructions *instr, champions *champ, circular_memory *vm);
	int		i = 0;
	instructions	*tmp = champ->list;

	init_exec_instru_tab(exec_tab);
	while (tmp != NULL) {
		exec__tab[recup_instruction(tmp->mnemonique)](tmp, champ, vm);
		printf("----- mnemo tmp1 %s ------\n", tmp->mnemonique);
		tmp1 = tmp1->next;
	}
}
