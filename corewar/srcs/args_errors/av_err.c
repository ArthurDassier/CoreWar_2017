/*
** EPITECH PROJECT, 2017
** av_err.c
** File description:
** Arthur
*/

#include "err_gest.h"

int g_flag(char *av)
{
	if (av[0] == '-' && av[1] == 'g')
		return (84);
	//my_puterror("we don't have any graphic interface");
	return (0);
}

int hexa_gest(char *av)
{
	int i = 1;
	int j = 0;
	char hexa[16] = "0123456789ABCDEF";

	while (av[i] != '\0') {
		while(av[i] != hexa[j] && hexa[j] != '\0')
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
