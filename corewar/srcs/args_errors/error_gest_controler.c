/*
** EPITECH PROJECT, 2017
** err_gs_acav.c
** File description:
** Arthur
*/

#include "my.h"

void put_compil_error(void)
{
	my_puterror("Usage: ./corewar [-g] [-dump cycle_nb] "
	"[[-a load_addr] [-n prog_nb] prog.cor] ...\n");
}

int ar_er(int ac, char **av)
{
	int	fl = 1;

	if (check_one_ac(ac) == 84)
		return (84);
	if (g_flag(av[1]) == 84)
		return (84);
	if ((fl = looking_for_flag(av)) == 84)
		return (84);
	if (check_cor(ac, av, fl) == 84)
		return (84);
	return (0);
}
