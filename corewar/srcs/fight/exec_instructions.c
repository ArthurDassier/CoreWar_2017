/*
** EPITECH PROJECT, 2017
** exec_instructions.c
** File description:
** exec_instructions_c_
*/

#include "virtual.h"

<<<<<<< HEAD
=======
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
			//	recup_instruction(tmp, vm, champ[j]);
				break;
			}
			if (i < cycle)
				break;
			}
		cycle = 0;
		++j;
	}
}

>>>>>>> a81b7443a097c271a058bf04db3d99efbfb43fd7
int cycles(circular_memory *vm, champions **champ)
{
	int	cycle_to_die = CYCLE_TO_DIE;
	int	cycle_delta = CYCLE_DELTA;
	int	i = 0;

	vm->nbr_live = 0;
	while (cycle_to_die > 0) {
		while (i != cycle_to_die) {
<<<<<<< HEAD
=======
		//	num_cycle(i, vm, champ);
>>>>>>> a81b7443a097c271a058bf04db3d99efbfb43fd7
			++i;
		}
		i = 0;
		cycle_to_die -= cycle_delta;
	}
	return (0);
}

void init_exec_instru_tab(int (*exec_instru_tab[16])(circular_memory *vm,
champions *champ))
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
