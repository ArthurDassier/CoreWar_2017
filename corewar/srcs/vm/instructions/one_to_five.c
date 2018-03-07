/*
** EPITECH PROJECT, 2017
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void live(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) champ;
	(void) vm;
	my_printf("Le joueur %X (?) est en vie.\n", instr->arg1);
}

void ld(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg2 = my_getnbr((champ->PC + instr->arg1 % IDX_MOD));
	champ->carry = modif_carry(champ->carry);
}

void st(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	if (instr->arg2 > REG_NUMBER)
		champ->PC = (champ->PC + instr->arg2 % IDX_MOD);
	else
		instr->arg2 = instr->arg1;
}

void add(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg3 = instr->arg1 + instr->arg2;
	champ->carry = modif_carry(champ->carry);
}

void sub(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg3 = instr->arg1 - instr->arg2;
	champ->carry = modif_carry(champ->carry);
}
