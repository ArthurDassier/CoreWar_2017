/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Arthur
*/

#include "my.h"

int virtual_machine(char **av)
{
	arguments	argv;
	char		*memory_zone = init_vm(av, &argv);

	if (memory_zone == NULL)
		return (84);
	cycles(memory_zone, &argv);
	free(memory_zone);
	return (0);
}

int main(int ac, char **av)
{
	instructions	**list = malloc(sizeof(instructions) * ac);

	if (ar_er(ac, av) > 0)
		return (84);
	if (virtual_machine(av) == 84)
		return (84);
	if (init_data_base(list, ac, av) == 84)
		return (84);
	return (0);
}
