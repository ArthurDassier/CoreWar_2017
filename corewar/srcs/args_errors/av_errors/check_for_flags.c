/*
** EPITECH PROJECT, 2017
** check_for_flags.c
** File description:
** Arthur
*/

#include "op.h"
#include "err_gest.h"

int double_fg(char flag)
{
	static int	flag_dump = OFF;
	static int	flag_n = OFF;
	static int	flag_a = OFF;

	if (flag == 'd' && flag_dump == OFF) {
		flag_dump = ON;
		return (D);
	}
	if (flag == 'n' && flag_n == OFF) {
		flag_n = ON;
		return (N);
	}
	if (flag == 'a' && flag_a == OFF) {
		flag_a = ON;
		return (A);
	}
	return (84);
}

int check_params(char **av, int i)
{
	if (!av[i + 1]) {
		//my_puterror("Usage: ./corewar [-g] [-dump cycle_nb] [[-a load_addr] [-n prog_nb] prog.cor] ...");
		return (84);
	}
	return (0);
}

static void init_flag_handler(int (*flag_handler[3])(char *flag, char *av))
{
	flag_handler[0] = &hexa_gest;
	flag_handler[1] = &check_fl_a;
	flag_handler[2] = &check_fl_n;
}

int send_to_flag_handler(int (*flag_handler[3])(char *flag, char *av), int nb_hyp, char *flag, char *av)
{
	int fg = 0;

	if ((fg = double_fg(flag[1])) == 84)
		return (84);
	nb_hyp = nb_hyp + 2;
	if (check_params(&av, 1) == 84)
		return (84);
	if (flag_handler[fg](flag, av) == 84)
		return (84);
	return (nb_hyp);
}

int looking_for_flag(char **av)
{
	int	nb_hyp = 1;
	int	(*flag_handler[3])(char *flag, char *av);

	init_flag_handler(flag_handler);
	if (av[1][0] == '-') {
		if (!av[2] || (nb_hyp = send_to_flag_handler(flag_handler, nb_hyp, av[1], av[2])) == 84)
			return (84);
	}
	if (av[3] && av[3][0] == '-') {
		if (!av[4] || (nb_hyp = send_to_flag_handler(flag_handler, nb_hyp, av[3], av[4])) == 84)
			return (84);
	}
	if (av[5] && av[5][0] == '-') {
		if (!av[6] || (nb_hyp = send_to_flag_handler(flag_handler, nb_hyp, av[5], av[6])) == 84)
			return (84);
	}
	return (nb_hyp);
}
