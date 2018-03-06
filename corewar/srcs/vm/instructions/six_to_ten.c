/*
** EPITECH PROJECT, 2017
** six_to_ten.c
** File description:
** Arthur
*/

#include "virtual.h"

void and(int *first, int *two, int *register_one)
{
	(void) *first;
	(void) *two;
	(void) *register_one;
	//modif carry;
	*register_one = *first & *two;
}

void or(int *first, int *two, int *register_one)
{
	(void) *first;
	(void) *two;
	(void) *register_one;
	//modif carry;
	*register_one = *first | *two;
}

void xor(int *first, int *two, int *register_one)
{
	(void) *first;
	(void) *two;
	(void) *register_one;
	//modif carry;
	*register_one = *first ^ *two;
}

void zjmp(int *index_one)
{
	(void) *index_one;
	//if (carry == 1)
		//PC = PC + index_one % IDX_MOD;
	//else
		//return;
	return;
}

void ldi(int *index_one, int *index_two, int *register_one)
{
	(void) *index_one;
	(void) *index_two;
	(void) *register_one;
	//IND_SIZE :
	//S = (PC + index_one % IDX_MOD) + index_two;
	//REG_SIZE :
	//register_one = PC + S % IDX_MOD;
	return;
}
