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
	(void) instr;
	(void) champ;
	(void) vm;
	//my_printf("Le joueur %d (?) est en vie.", instr->arg1);
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
	if ((instr->types / 10) % 10 != 2)
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
