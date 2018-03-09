/*
** EPITECH PROJECT, 2017
** pars_champ.c
** File description:
** pars_champ.c
*/

#include "virutal.h"

int champ_instru(champions *champ)
{
	int	inst = 0;

	inst = *champ->PC % 16 + 48;
	++champ->PC;
	inst = inst * 10 + (*champ->PC % 16) + 48;
	++champ->PC;
	champ->tmp = champ->PC;
	if (inst < 1 || inst > 16)
		return (-1);
	else
		return (inst);
}

int champ_adr(champions *champ, int nb_args)
{
	int	types = 0;
	int	adr = 0;

	adr = *champ->PC % 16 + 48;
	++champ->PC;
	adr = adr * 10 + (*champ->PC % 16) + 48;
	++champ->PC;
	return (adr);
}

int champ_params_types(champions *champ, int adr, int nb_params)
{
	int	types = 0;
	int	bin = 0;
	int	val = 0;
	int	i = 0;

	if (nb_params == 2) {
		++nb_arg;
		loop = 1;
	}
}
