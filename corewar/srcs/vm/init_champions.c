/*
** EPITECH PROJECT, 2017
** init_champions.c
** File description:
** init_champions_c
*/

#include "virtual.h"

int init_champions(champions **champ, int ac, char **av)
{
	instructions	**data_base = malloc(sizeof(instructions) * ac);
	int		i = 0;

	if (init_data_base(data_base, ac, av) == -1)
		return (-1);
	while (data_base[i] != NULL) {
		champ[i] = malloc(sizeof(champions));
		memset_champion_registers(champ[i]);
		champ[i]->list = data_base[i];
		++i;
	}
	champ[i] = NULL;
	return (0);
}

void memset_champion_registers(champions *champ)
{
	int	i = 0;

	champ->registers = malloc(sizeof(int) * 17);
	while (i != 16)
		champ->registers[i++] = 0;
	champ->registers[i] = 0;
}
