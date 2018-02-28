/*
** EPITECH PROJECT, 2017
** cycles.c
** File description:
** Arthur
*/

#include "my.h"
#include "printf.h"

void num_cycle(int i, char *memory_zone, instructions **list, arguments *argv)
{
	(void) memory_zone;
	(void) argv;
	(void) list;
	my_printf("CYCLE_TO_DIE n°: %d\n", i);
}

int cycles(char *memory_zone, instructions **list, arguments *argv)
{
	int	cycle_to_die = CYCLE_TO_DIE;
	int	cycle_delta = CYCLE_DELTA;
	int	i = 0;

	while (cycle_to_die > 0) {
		while (i != cycle_to_die) {
			num_cycle(i, memory_zone, list, argv);
			++i;
		}
		i = 0;
		cycle_to_die -= cycle_delta;
	}
	return (0);
}
