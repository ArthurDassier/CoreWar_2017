/*
** EPITECH PROJECT, 2017
** six_to_ten.c
** File description:
** Arthur
*/

#include "virtual.h"

void and_inst(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) instr;
	(void) champ;
	(void) vm;
	instr->arg1 = instr->arg2 & instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void or_inst(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) instr;
	(void) champ;
	(void) vm;
	instr->arg1 = instr->arg2 | instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void xor_inst(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) instr;
	(void) champ;
	(void) vm;
	instr->arg1 = instr->arg2 ^ instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void zjmp(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) instr;
	(void) champ;
	(void) vm;
	if (champ->carry == 1)
		champ->PC = champ->PC + instr->arg1 % IDX_MOD;
}

void ldi(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) instr;
	(void) champ;
	(void) vm;
	int	S = 0;

	champ->tmp = champ->PC + instr->arg1 % IDX_MOD;
	S = (my_getnbr(champ->tmp) + my_getnbr((champ->tmp + 1)) + my_getnbr((champ->tmp + 2)) + my_getnbr((champ->tmp + 3))) + instr->arg2;
	champ->tmp = champ->PC + S % IDX_MOD;
	instr->arg3 = my_getnbr(champ->tmp) + my_getnbr((champ->tmp + 1)) + my_getnbr((champ->tmp + 2)) + my_getnbr((champ->tmp + 3));
}
