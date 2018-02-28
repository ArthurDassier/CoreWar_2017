/*
** EPITECH PROJECT, 2017
** cycles.c
** File description:
** Arthur
*/

#include "my.h"
#include "printf.h"

void num_cycle(int i, circular_memory *vm, champions **champ, arguments *argv)
{
	int cycle = 0;
	
}

int cycles(circular_memory *vm, champions **champ, arguments *argv)
{
	int	cycle_to_die = CYCLE_TO_DIE;
	int	cycle_delta = CYCLE_DELTA;
	int	i = 0;

	while (cycle_to_die > 0) {
		while (i != cycle_to_die) {
			num_cycle(i, vm, champ, argv);
			++i;
		}
		i = 0;
		cycle_to_die -= cycle_delta;
	}
	return (0);
}
