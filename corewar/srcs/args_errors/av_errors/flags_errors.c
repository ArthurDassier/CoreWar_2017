/*
** EPITECH PROJECT, 2017
** flags_err.c
** File description:
** Arthur
*/

#include "err_gest.h"

int check_dump(char *av)
{
	char	dmp[5] = "-dump";
	int	i = 0;

	while (av[i] != '\0' && dmp[i] != '\0') {
		if (av[i] != dmp[i])
			return (84);
		++i;
	}
	if (av[i] != dmp[i])
		return (84);
	return (0);
}

int check_fl_n(char *flag, char *av)
{
	char	base[10] = "0123456789";
	int	i = 0;
	int	j = 0;

	if (flag[1] != 'n')
		return (84);
	while (av[i] != '\0') {
		while (base[j] != av[i] && base[j] != '\0')
			++j;
		if (base[j] == '\0')
			return (84);
		j = 0;
		++i;
	}
	return (0);
}

int check_fl_a(char *flag, char *params)
{
	char	hexa[16] = "0123456789ABCDEF";
	int	i = 1;
	int	j = 0;

	if (flag[1] != 'a')
		return (84);
	while (params[i] != '\0') {
		while (params[i] != hexa[j] && hexa[j] != '\0')
			++j;
		if (hexa[j] == '\0')
			return (84);
		j = 0;
		++i;
	}
	if (i == 1)
		return (84);
	return (0);
}

int g_flag(char *av)
{
	if (av[0] == '-' && av[1] == 'g')
		return (84);
	//my_puterror("we don't have any graphic interface");
	return (0);
}

int hexa_gest(char *av, char *params)
{
	char	hexa[16] = "0123456789ABCDEF";
	int	i = 1;
	int	j = 0;

	if (check_dump(av) == 84)
		return (84);
	while (params[i] != '\0') {
		while (params[i] != hexa[j] && hexa[j] != '\0')
			++j;
		if (hexa[j] == '\0')
			return (84);
		j = 0;
		++i;
	}
	if (i == 1)
		return (84);
	return (0);
}
