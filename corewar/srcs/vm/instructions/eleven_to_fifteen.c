/*
** EPITECH PROJECT, 2017
** eleven_to_fifteen.c
** File description:
** Arthur
*/

#include "virtual.h"

void sti(int *register_one, int *param_one, int *param_two)
{
	(void) *register_one;
	(void) *param_one;
	(void) *param_two;
//	PC + (param_one + param_two) % IDX_MOD = register_one;
	return;
}

void fork_inst(int *index_one)
{
	(void) *index_one;
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one % IDX_MOD.*/
	return;
}

void lld(int *param_one, int *register_one)
{
	(void) *param_one;
	(void) *register_one;
	//register_one = (PC + *param_one);
	//modif carry;
	return;
}

void lldi(int *index_one, int *index_two, int *register_one)
{
	(void) *index_one;
	(void) *index_two;
	(void) *register_one;
	//IND_SIZE :
	//S = (PC + index_one) + index_two;
	//REG_SIZE :
	//register_one = PC + S;
	//modif carry;
	return;
}

void lfork(int *index_one)
{
	(void) *index_one;
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one.*/
	return;
}
