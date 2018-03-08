/*
** EPITECH PROJECT, 2017
** fight_loop.c
** File description:
** loop_for_cores_fight
*/

#include "virtual.h"

void set_cycles(int *cycles, int *max, int delta)
{
	if (*cycles == *max) {
		*cycles = 1;
		*max -= delta;
	}
}

void loop_fight(circular_memory *vm, champions **champ)
{
	int	cycles = 1;
	int	max = CYCLES_TO_DIE;
	int	delta = CYCLES_DELTA;
	int	lives = NBR_LIVE;
	int	i = 0;

	while (cycles != (max + 1)) {
		while (champ[i])
			do_instruction(champ[i++]);
		i = 0;
		set_cycles(cycles, max, delta);
		++cycles;
	}
}
