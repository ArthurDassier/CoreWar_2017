/*
** EPITECH PROJECT, 2017
** clist_argv.c
** File description:
** Arthur
*/

#include "data_base.h"

int find_a(char **av, int i)
{
	if (av[i - 2][1] == 'a')
		return (my_getnbr(av[i - 1]));
	if (av[i - 4][1] == 'a')
		return (my_getnbr(av[i - 3]));
	return (0);
}

int find_n(char **av, int i)
{
	if (av[i - 2][1] == 'n')
		return (my_getnbr(av[i - 1]));
	if (av[i - 4][1] == 'n')
		return (my_getnbr(av[i - 3]));
	return (0);
}

void put_in_list(arg_champ *clist, char **av, int i)
{
	static int	status = 0;

	if (status == 0) {
		clist = init_ag_champ(find_a(av, i), find_n(av, i), av[i]);
		status = 1;
	} else
		insert_end(&clist, find_a(av, i), find_n(av, i), av[i]);
}

int verif_cor(char *av)
{
	int	i = 0;

	while (av[i] != '\0') {
		if (av[i] == '.')
			return (1);
		++i;
	}
	return (0);
}

arg_champ *put_arg(int ac, char **av)
{
	int		i = 1;
	arg_champ	*clist = NULL;

	while (i != ac) {
		if (verif_cor(av[i]) == 1) {
			put_in_list(clist, av, i);
		}
		++i;
	}
	return (clist);
}
