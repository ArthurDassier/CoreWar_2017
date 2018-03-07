/*
** EPITECH PROJECT, 2017
** eleven_to_fifteen.c
** File description:
** Arthur
*/

#include "struct.h"
#include "instructions.h"

void sti(instructions *instr, champions *champ)
{
	//champ->PC + (instr->arg2 + instr->arg3) % IDX_MOD = instr->arg1;
	return;
}

void fork_inst(instructions *instr, champions *champ)
{
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one % IDX_MOD.*/
	return;
}

void lld(instructions *instr, champions *champ)
{
	instr->arg2 = (champ->PC + instr->arg1);
	champ->carry = modif_carry(champ->carry);
}

void lldi(instructions *instr, champions *champ)
{
	//IND_SIZE :
	//S = (champ->PC + instr->arg1) + instr->arg2;
	//REG_SIZE :
	//instr->arg3 = champ->PC + S;
	champ->carry = modif_carry(champ->carry);
}

void lfork(instructions *instr, champions *champ)
{
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one.*/
	return;
}
