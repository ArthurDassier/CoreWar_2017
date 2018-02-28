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

char *init_vm(char **av, arguments *argv)
{
	char	*memory_zone = malloc(sizeof(char) * MEM_SIZE);
	int	i = 0;

	if (memory_zone == NULL) {
		my_puterror("/!\\ MALLOC == NULL /!\\\n");
		return (NULL);
	}
	while (av[i]) {
		if (av[i][0] == '-')
			fill_arg(argv, av[i], av[i + 1]);
		++i;
	}
	return (memory_zone);
}
