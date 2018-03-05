/*
** EPITECH PROJECT, 2017
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"

void live(int player_number)
{
	my_printf("Le joueur %d (?) est en vie.", player_number)
}

void add(int *register_one, int *register_two, int *register_three)
{
	*register_three = *register_one + *register_two;
}

void sub(int *register_one, int *register_two, int *register_three)
{
	*register_three = *register_one - *register_two;
}
