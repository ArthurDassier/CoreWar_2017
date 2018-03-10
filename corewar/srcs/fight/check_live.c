/*
** EPITECH PROJECT, 2018
** check_live.c
** File description:
** Arthur
*/

#include "virtual.h"

int id_win(champions **champ, int last_live)
{
	int	i = 0;

	while (champ[i] != NULL) {
		if (champ[i]->registers[0] == last_live)
		return (champ[i]->registers[0]);
		++i;
	}
	return (-1);
}

char *name_win(champions **champ, int last_live)
{
	int	nb = id_win(champ, last_live);

	return (champ[nb]->champ_name[champ[nb]->register[0] - 1]);
}


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
	} else {
		my_printf("Le joueur %d (%s) a gagné.\n",
		id_win(champ, vm->last_live), name_win(champ, last_live));
		exit (0);
	}
}
