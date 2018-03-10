/*
** EPITECH PROJECT, 2017
** fight_loop.c
** File description:
** loop_for_cores_fight
*/

#include "virtual.h"

int fight_loop(circular_memory *vm, champions **champ)
{
	int	cycle_to_die = CYCLE_TO_DIE;
	int	cycle_delta = CYCLE_DELTA;
	int	i = 0;

	vm->nbr_live = 0;
	while (cycle_to_die > 0) {
		while (i != cycle_to_die) {
		//	instructions de vincent;
			++i;
		}
		i = 0;
		cycle_to_die -= cycle_delta;
	}
	return (0);
}
