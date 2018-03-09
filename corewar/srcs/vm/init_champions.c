/*
** EPITECH PROJECT, 2017
** init_champions.c
** File description:
** init_champions_c
*/

#include "virtual.h"

int init_champions(champions **champ, arg_champ *av_list)
{
	int		i = 0;
	instructions	**data_base = malloc(sizeof(instructions) *
			av_list->nbr_champ);

	if (data_base == NULL)
		return (84);
	if (init_data_base(data_base, av_list) == -1)
		return (84);
	while (data_base[i] != NULL) {
		if ((champ[i] = malloc(sizeof(champions))) == NULL)
			return (84);
		if (memset_champion_registers(champ[i]) == 84)
			return (84);
		champ[i]->list = data_base[i];
		++i;
	}
	champ[i] = NULL;
	return (0);
}

int memset_champion_registers(champions *champ)
{
	int	i = 0;

	champ->registers = malloc(sizeof(int) * 17);
	if (champ->registers == NULL)
		return (84);
	while (i != 16)
		champ->registers[i++] = 0;
	champ->registers[i] = 0;
	champ->carry = 0;
	return (0);
}
