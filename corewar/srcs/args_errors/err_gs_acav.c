/*
** EPITECH PROJECT, 2017
** err_gs_acav.c
** File description:
** Arthur
*/

#include "op.h"
#include "err_gest.h"

int ar_er(int ac, char **av)
{
	(void) av;
	if (check_ac_nb(ac) == 84)
		return (84);
	if (check_one_ac(ac) == 84)
		return (84);
	return (0);
}
