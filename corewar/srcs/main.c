/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Arthur
*/

#include "op.h"
#include "err_gest.h"
#include <stdlib.h>

void fill_arg(arguments *argv, char *flag, char *parameter)
{
	if (flag[1] == 'a') {
		argv->on_a = ON;
		argv->flg_a = parameter;
	} else if (flag[1] == 'n') {
		argv->on_n = ON;
		argv->flg_n = parameter;
	} else {
		argv->on_dump = ON;
		argv->flg_dump = parameter;
	}
}

int vm(char **av)
{
	arguments	argv;
	int		i = 0;

	while (av[i]) {
		if (av[i][0] == '-')
			fill_arg(&argv, av[i], av[i + 1]);
		++i;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ar_er(ac, av) > 0)
		return (84);
	vm(av);
	return (0);
}
