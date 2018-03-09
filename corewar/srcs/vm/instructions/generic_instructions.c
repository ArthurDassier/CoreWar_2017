/*
** EPITECH PROJECT, 2018
** generic_instructions.c
** File description:
** Arthur
*/

#include "virtual.h"

int name(champions *champ, int types)
{
	int	nbr = 0;

	for (int i = 0; i != types; ++i) {
		champ->tmp += 1;
		nbr += my_getnbr(*champ->tmp);
		nbr *= 10;
	}
	return (nbr);
}
