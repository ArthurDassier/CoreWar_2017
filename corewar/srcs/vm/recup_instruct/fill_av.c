/*
** EPITECH PROJECT, 2017
** init_vm.c
** File description:
** Arthur
*/

#include "my.h"

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

arguments *init_vm(char **av, arguments *argv)
{
	int	i = 0;

	while (av[i]) {
		if (av[i][0] == '-')
			fill_arg(argv, av[i], av[i + 1]);
		++i;
	}
	return (argv);
}
