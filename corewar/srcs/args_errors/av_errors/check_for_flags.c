/*
** EPITECH PROJECT, 2017
** check_for_flags.c
** File description:
** Arthur
*/

#include "my.h"

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
		put_compil_error();
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

int send_to_flag_handler(int (*flag_handler[3])(char *flag, char *av),
int nb_hyp, char *flag, char *av)
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
		if (looking_for_flag_err(flag_handler, av, 1, nb_hyp) == 84)
			return (84);
	}
	if (av[3] && av[3][0] == '-') {
		if (looking_for_flag_err(flag_handler, av, 3, nb_hyp) == 84)
			return (84);
	}
	if (av[5] && av[5][0] == '-') {
		if (looking_for_flag_err(flag_handler, av, 5, nb_hyp) == 84)
			return (84);
	}
	return (nb_hyp);
}
