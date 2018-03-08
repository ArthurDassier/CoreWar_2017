/*
** EPITECH PROJECT, 2017
** param_error.c
** File description:
** param_error.c
*/

#include "virtual.h"

static int recup_type(int types)
{
	if (types == 2)
		return (T_REG);
	if (types == 8)
		return (T_DIR);
	if (types == 4)
		return (T_IND);
	return (0);
}
static int or_types(int types)
{
	int	nb1 = 0;
	int	nb2 = 0;
	int	nb3 = 0;

	nb1 = recup_type(types / 10);
	nb2 = recup_type(types / 10 % 10);
	nb3 = recup_type(types % 10);
	return (nb1 | nb2 | nb3);
}

int is_good_params(instructions *list)
{
	int	ins_case = 0;

	ins_case = list->mnemonique[0] % 16 + 48;
	ins_case = ins_case * 10 + list->mnemonique[1] % 16 + 48;
	if (or_types(list->types) != op_tab[ins_case - 1].type[2])
		return (-1);
	return (0);
}
