/*
** EPITECH PROJECT, 2017
** argc_err.c
** File description:
** Arthur
*/

#include "my.h"

int check_one_ac(int ac)
{
	if (ac == 1 || ac == 2) {
		put_compil_error();
		return (84);
	}
	return (0);
}
