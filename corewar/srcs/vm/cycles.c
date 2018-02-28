/*
** EPITECH PROJECT, 2017
** cycles.c
** File description:
** Arthur
*/

#include "my.h"
#include "printf.h"

void num_cycle(int i)
{
	my_printf("CYCLE_TO_DIE n°: %d\n", i);
}

int cycles(char *memory_zone, arguments *argv)
{
	int	cycle_to_die = CYCLE_TO_DIE;
	int	cycle_delta = CYCLE_DELTA;
	int	i = 0;

	(void) memory_zone;
	(void) argv;
	while (cycle_to_die > 0) {
		while (i != cycle_to_die) {
			num_cycle(i);
			++i;
		}
		i = 0;
		cycle_to_die -= cycle_delta;
	}
	return (0);
}
