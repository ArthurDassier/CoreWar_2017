/*
** EPITECH PROJECT, 2017
** power
** File description:
** power it
*/
#include "corewar.h"

int my_compute_power_rec(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p > 0)
		return (nb * my_compute_power_rec(nb, p - 1));
	return (0);
}