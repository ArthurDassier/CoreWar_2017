/*
** EPITECH PROJECT, 2017
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void live(int player_number)
{
	my_printf("Le joueur %d (?) est en vie.", player_number);
}

void ld(instructions *instr, champions *champ)
{
	instr->arg2 = (champ->PC + instr->arg1 % IDX_MOD);
	champ->carry = modif_carry(champ->carry);
	return;
}

void st(instructions *instr, champions *champ)
{
	//if (instr->arg2 != register)
		//(champ->PC + instr->arg2 % IDX_MOD) = instr->arg1;
	//else
		//instr->arg2 = instr->arg1;
	return;
}

void add(instructions *instr, champions *champ)
{
	instr->arg3 = instr->arg1 + instr->arg2;
	champ->carry = modif_carry(champ->carry);
}

void sub(instructions *instr, champions *champ)
{
	instr->arg3 = instr->arg1 - instr->arg2;
	champ->carry = modif_carry(champ->carry);
}
