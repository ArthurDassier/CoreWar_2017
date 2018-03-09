/*
** EPITECH PROJECT, 2018
** eleven_to_fifteen.c
** File description:
** Arthur
*/

#include "virtual.h"

void sti_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	int	i = 0;
	char	*str = its(instr->arg1);

	champ->tmp = champ->PC + (instr->arg2 + instr->arg3) % IDX_MOD;
	memory_put_move(vm, champ, str[i++], 0);
	while (str[i] != '\0')
		memory_put_move(vm, champ, str[i++], 1);
	champ->tmp = champ->PC;
}

void fork_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) instr;
	(void) champ;
	(void) vm;
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one % IDX_MOD.*/
	return;
}

void lld_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg2 = my_getnbr((champ->PC + instr->arg1));
	champ->carry = modif_carry(champ->carry);
}

void lldi_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	int	S = 0;

	(void) vm;
	champ->tmp = champ->PC + instr->arg1;
	S = (my_getnbr(champ->tmp) + my_getnbr((champ->tmp + 1))
	+ my_getnbr((champ->tmp + 2)) + my_getnbr((champ->tmp + 3)))
	+ instr->arg2;
	champ->tmp = champ->PC + S;
	instr->arg3 =  my_getnbr(champ->tmp) + my_getnbr((champ->tmp + 1))
	+ my_getnbr((champ->tmp + 2)) + my_getnbr((champ->tmp + 3));
	champ->carry = modif_carry(champ->carry);
	champ->tmp = champ->PC;
}

void lfork_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) instr;
	(void) champ;
	(void) vm;
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one.*/
	return;
}
