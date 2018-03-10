/*
** EPITECH PROJECT, 2017
** get_nbr_from_size.c
** File description:
** get_nbr_from_size_c_
*/

#include "virtual.h"

int getnbr_from_size(champions *champ, int size)
{
	int	i = 0;
	char	*tmp = malloc(sizeof(char) * (size + 1));
	int	nb = 0;

	while (i != size) {
		tmp[i++] = *champ->tmp;
		++champ->tmp;
	}
	tmp[i] = '\0';
	++champ->tmp;
	nb = my_getnbr_base(tmp, "0123456789ABCDEF");
	free(tmp);
	return (nb);
}
