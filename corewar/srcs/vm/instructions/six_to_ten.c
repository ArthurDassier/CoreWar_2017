/*
** EPITECH PROJECT, 2018
** six_to_ten.c
** File description:
** Arthur
*/

#include "virtual.h"

void and_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg1 = instr->arg2 & instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void or_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg1 = instr->arg2 | instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void xor_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg1 = instr->arg2 ^ instr->arg3;
	champ->carry = modif_carry(champ->carry);
}

void zjmp_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	if (champ->carry == 1)
		champ->PC = champ->PC + instr->arg1 % IDX_MOD;
	champ->tmp = champ->PC;
}

void ldi_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	int	S = 0;

	(void) vm;
	champ->tmp = champ->PC + instr->arg1 % IDX_MOD;
	S = (my_getnbr(champ->tmp) + my_getnbr((champ->tmp + 1))
	+ my_getnbr((champ->tmp + 2)) + my_getnbr((champ->tmp + 3)))
	+ instr->arg2;
	champ->tmp = champ->PC + S % IDX_MOD;
	instr->arg3 = my_getnbr(champ->tmp) + my_getnbr((champ->tmp + 1))
	+ my_getnbr((champ->tmp + 2)) + my_getnbr((champ->tmp + 3));
	champ->tmp = champ->PC;
}
