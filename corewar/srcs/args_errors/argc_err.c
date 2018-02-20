/*
** EPITECH PROJECT, 2017
** argc_err.c
** File description:
** Arthur
*/

#include "op.h"
#include "err_gest.h"

int check_ac_nb(int ac)
{
	if (ac > MAX_ARGS_NUMBER)
		return (84);
	//my_puterror("Too many arguments\n");
	return (0);
}

int check_one_ac(int ac)
{
	if (ac == 1 || ac == 2)
		return (84);
	//my_puterror("Usage: ./corewar [-g] [-dump cycle_nb] [[-a load_addr] [-n prog_nb] prog.cor] ...");
	return (0);
}
