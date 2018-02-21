/*
** EPITECH PROJECT, 2017
** err_gs_acav.c
** File description:
** Arthur
*/

#include "op.h"
#include "err_gest.h"

int check_parms(char **av, int i)
{
	if (!av[i + 1]) {
		//my_puterror("Usage: ./corewar [-g] [-dump cycle_nb] [[-a load_addr] [-n prog_nb] prog.cor] ...");
		return (84);
	}
	return (0);
}

int lff(char **av)
{
	int	nb_hyp = 1;

	if (av[1][0] == '-') {
		nb_hyp = 3;
		if (check_parms(av, 1) == 84)
			return (84);
		if (hexa_gest(av[1], av[2]) == 84)
			return (84);
	}
	if (av[3] && av[3][0] == '-') {
		nb_hyp = 5;
		if (check_parms(av, 3) == 84)
			return (84);
		if (check_fl_n(av[3], av[4]) == 84)
			return (84);
	}
	if (av[5] && av[5][0] == '-') {
		nb_hyp = 7;
		if (check_parms(av, 5) == 84)
			return (84);
		if (check_fl_a(av[5], av[6]) == 84)
			return (84);
	}
	return (nb_hyp);
}

int ar_er(int ac, char **av)
{
	int	fl = 1;

	if (check_ac_nb(ac) == 84)
		return (84);
	if (check_one_ac(ac) == 84)
		return (84);
	if (g_flag(av[1]) == 84)
		return (84);
	if ((fl = lff(av)) == 84)
		return (84);
	if (check_cor(ac, av, fl) == 84)
		return (84);
	return (0);
}
