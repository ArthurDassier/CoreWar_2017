/*
** EPITECH PROJECT, 2017
** pars_champ.c
** File description:
** pars_champ.c
*/

#include "virtual.h"

int champ_instru(champions *champ)
{
	int	inst = 0;
	char	*tmp = malloc(sizeof(char) * 3);

	tmp[0] = *champ->tmp;
	++champ->tmp;
	tmp[1] = *champ->tmp;
	tmp[2] = '\0';
	++champ->tmp;
	inst = my_getnbr_base(tmp, "0123456789ABCDEF");
	free(tmp);
	printf("---> ins %d\n", inst);
	if (inst < 1 || inst > 16)
		return (-1);
	else
		return (inst);
}

int champ_adr(champions *champ)
{
	int	adr = 0;
	char	*tmp = malloc(sizeof(char) * 3);

	tmp[0] = *champ->tmp;
	++champ->tmp;
	tmp[1] = *champ->tmp;
	tmp[2] = '\0';
	++champ->tmp;
	adr = my_getnbr_base(tmp, "0123456789ABCDEF");
	free(tmp);
	champ->PC = champ->tmp;
	printf("---> adr %d\n", adr);
	return (adr);
}

int champ_params_types(int inst, int adr, int nb_params)
{
	int	types = 0;
	int	bin = 0;
	int	val = 0;
	int	loop = 0;

	if (nb_params == 2) {
		++nb_params;
		loop = 1;
	}
	while (nb_params != loop) {
		val = (adr >> nb_params * 2) ^ bin;
		types = types +  val * 2 * 10;
		bin |= adr >> (nb_params * 2);
		bin <<= 2;
		--nb_params;
	}
	if (is_good_params(types, inst) != 0)
		return (-1);
	return (types);
}
