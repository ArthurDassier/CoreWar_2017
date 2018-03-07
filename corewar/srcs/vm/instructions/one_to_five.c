/*
** EPITECH PROJECT, 2017
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"
#include "op.h"

void live(instructions *instr, champions *champ, circular_memory *vm)
{
	//my_printf("Le joueur %d (?) est en vie.", player_number);
}

void ld(instructions *instr, champions *champ, circular_memory *vm)
{
	instr->arg2 = (champ->PC + instr->arg1 % IDX_MOD);
	champ->carry = modif_carry(champ->carry);
}

void st(instructions *instr, champions *champ, circular_memory *vm)
{
	//if (instr->arg2 != register)
		//(champ->PC + instr->arg2 % IDX_MOD) = instr->arg1;
	//else
		//instr->arg2 = instr->arg1;
	return;
}

void add(instructions *instr, champions *champ, circular_memory *vm)
{
	instr->arg3 = instr->arg1 + instr->arg2;
	champ->carry = modif_carry(champ->carry);
}

void sub(instructions *instr, champions *champ, circular_memory *vm)
{
	instr->arg3 = instr->arg1 - instr->arg2;
	champ->carry = modif_carry(champ->carry);
}
