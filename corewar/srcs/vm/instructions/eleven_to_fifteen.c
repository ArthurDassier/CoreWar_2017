/*
** EPITECH PROJECT, 2018
** eleven_to_fifteen.c
** File description:
** Arthur
*/

#include "virtual.h"

void sti_instru(circular_memory *vm, champions *champ, int types)
{
	int	i = 0;
	char	*str = its(instr->arg1);

	champ->tmp += (instr->arg2 + instr->arg3) % IDX_MOD;
	memory_put_move(vm, champ, str[i++], 0);
	while (str[i] != '\0')
		memory_put_move(vm, champ, str[i++], 1);
	champ->tmp = champ->PC;
}

void fork_instru(circular_memory *vm, champions *champ, int types)
{
	(void) instr;
	(void) champ;
	(void) vm;
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one % IDX_MOD.*/
	return;
}

void lld_instru(circular_memory *vm, champions *champ, int types)
{
	int	ld = 0;
	int	rg = 0;
	int	nbr_to_load = 0;

	ld = getnbr_from_size(champ, types / 10);
	champ->PC = champ->tmp;
	rg = getnbr_from_size(champ, types % 10);
	champ->PC = champ->tmp;
	champ->tmp = champ->PC + ld;
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->tmp = champ->PC;
	if (rg > REG_NUMBER)
		return;
	champ->registers[rg] = nbr_to_load;
}

void lldi_instru(circular_memory *vm, champions *champ, int types)
{
	int	S = 0;

	(void) vm;
	champ->tmp = champ->PC + instr->arg1;
	for (int i = 0; i != IND_SIZE; ++i) {
		S += my_getnbr(champ->tmp);
		S *= 10;
		++champ->tmp;
	}
	S += instr->arg2;
	champ->tmp = champ->PC + S;
	instr->arg3 = 0;
	for (int i = 0; i != REG_SIZE; ++i) {
		instr->arg3 += my_getnbr(champ->tmp);
		instr->arg3 *= 10;
		++champ->tmp;
	}
	champ->tmp = champ->PC;
}

void lfork_instru(circular_memory *vm, champions *champ, int types)
{
	(void) instr;
	(void) champ;
	(void) vm;
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one.*/
	return;
}
