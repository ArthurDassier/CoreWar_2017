/*
** EPITECH PROJECT, 2018
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
	my_printf("Le joueur %d (?) est en vie.\n", instr->arg1);
}

void ld(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg2 = my_getnbr((champ->PC + instr->arg1 % IDX_MOD));
	champ->carry = modif_carry(champ->carry);
}

void st(instructions *instr, champions *champ, circular_memory *vm)
{
	char	*str = its(instr->arg1);

	if (instr->arg2 > REG_NUMBER) {
		champ->tmp = champ->PC;
		champ->PC = (champ->PC + instr->arg2 % IDX_MOD);
		memory_put_move(vm, champ, str[i++], 0);
		while (str[i] != '\0')
			memory_put_move(vm, champ, str[i++], 1);
		champ->PC = champ->tmp;
	} else
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
