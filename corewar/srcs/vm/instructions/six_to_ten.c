/*
** EPITECH PROJECT, 2017
** six_to_ten.c
** File description:
** Arthur
*/

#include "struct.h"
#include "instructions.h"
#include "op.h"

void and_inst(instructions *instr, champions *champ, circular_memory *vm)
{
	instr->arg1 = instr->arg2 & instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void or_inst(instructions *instr, champions *champ, circular_memory *vm)
{
	instr->arg1 = instr->arg2 | instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void xor_inst(instructions *instr, champions *champ, circular_memory *vm)
{
	instr->arg1 = instr->arg2 ^ instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void zjmp(instructions *instr, champions *champ, circular_memory *vm)
{
	if (champ->carry == 1)
		champ->PC = champ->PC + instr->arg1 % IDX_MOD;
}

void ldi(instructions *instr, champions *champ, circular_memory *vm)
{
	//IND_SIZE :
	//S = (champ->PC + instr->arg1 % IDX_MOD) + instr->arg2;
	//REG_SIZE :
	//instr->arg3 = champ->PC + S % IDX_MOD;
	return;
}
