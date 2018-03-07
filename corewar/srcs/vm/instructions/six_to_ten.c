/*
** EPITECH PROJECT, 2017
** six_to_ten.c
** File description:
** Arthur
*/

#include "virtual.h"

void and(instructions *instr, champions *champ)
{
	//modif carry;
	instr->arg1 = instr->arg2 & instr->arg3;
}

void or(instructions *instr, champions *champ)
{
	//modif carry;
	instr->arg1 = instr->arg2 | instr->arg3;
}

void xor(instructions *instr, champions *champ)
{
	//modif carry;
	instr->arg1 = instr->arg2 ^ instr->arg3;
}

void zjmp(instructions *instr, champions *champ)
{
	//if (carry == 1)
		//PC = PC + instr->arg1 % IDX_MOD;
	//else
		//return;
	return;
}

void ldi(instructions *instr, champions *champ)
{
	//IND_SIZE :
	//S = (champ->PC + instr->arg1 % IDX_MOD) + instr->arg2;
	//REG_SIZE :
	//instr->arg3 = champ->PC + S % IDX_MOD;
	return;
}
