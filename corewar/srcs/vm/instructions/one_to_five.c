/*
** EPITECH PROJECT, 2017
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void live(int player_number)
{
	my_printf("Le joueur %d (?) est en vie.", player_number);
}

void ld(int *param_one, int *register_one)
{
	(void) *param_one;
	(void) *register_one;
	//register_one = (PC + *param_one % IDX_MOD);
	//modif carry;
	return;
}

void st(int *register_one, int *param_two)
{
	(void) *param_one;
	(void) *param_two;
	//if (param_two != register)
		//(PC + *param_two % IDX_MOD) = register_one;
	//else
		//param_two = register_one;
	return;
}

void add(int *register_one, int *register_two, int *register_three)
{
	(void) *register_one;
	(void) *register_two;
	(void) *register_three;
	//modif carry;
	*register_three = *register_one + *register_two;
}

void sub(int *register_one, int *register_two, int *register_three)
{
	(void) *register_one;
	(void) *register_two;
	(void) *register_three;
	//modif carry;
	*register_three = *register_one - *register_two;
}
