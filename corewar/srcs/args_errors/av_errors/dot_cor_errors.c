/*
** EPITECH PROJECT, 2017
** av_err.c
** File description:
** Arthur
*/

#include "err_gest.h"

int check_each(char *av)
{
	char	cor[4] = ".cor";
	int	letter = 0;
	int	j = 0;

	while (av[j] != '.' && av[j] != '\0')
		++j;
	if (av[j] == '\0')
		return (84);
	while (av[j] != '\0') {
		if (av[j] != cor[letter])
			return (84);
		++j;
		++letter;
	}
	if (letter != 4)
		return (84);
	return (0);
}

int check_cor(int ac, char **av, int i)
{
	int	j = i;

	while (i != ac) {
		if (check_each(av[i]) == 84) {
			//my_puterror(av[i]);
			//my_puterror(" is not an executable.\n");
			return (84);
		}
		++i;
	}
	if (j == i || i == j + 1)
		return (84);
	return (0);
}
