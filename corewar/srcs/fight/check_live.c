/*
** EPITECH PROJECT, 2018
** check_live.c
** File description:
** Arthur
*/

#include "virtual.h"

void check_live(circular_memory *vm, champions **champ)
{
	int	i = 0;
	int	nbr_still_alive = 0;

	while (champ[i] != NULL) {
		if (champ[i]->live_nb > 0)
			++nbr_still_alive;
		++i;
	}
	if (nbr_still_alive > 1 && vm->nbr_live >= NBR_LIVE) {
		vm->nbr_live = 0;
		return;
	} else
		exit (0);
}
