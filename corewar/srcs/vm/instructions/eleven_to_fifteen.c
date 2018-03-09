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

	champ->tmp += (instr->arg2 + instr->arg3) % IDX_MOD;
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
	int	ld = 0;
	int	rg = 0;
	int	nbr_to_load = 0;

	for (int i = 0; i != types / 10; ++i) {
		champ->tmp = champ->PC + i;
		ld += my_getnbr(*champ->tmp);
		ld *= 10;
	}
	champ->tmp += champ->PC + types / 10;
	for (int i = 0; i != types % 10; ++i) {
		champ->tmp = champ->PC + i;
		rg += my_getnbr(*champ->tmp);
		rg *= 10;
	}
	champ->tmp = (champ->PC + ld) - 1;
	for (int i = 0; i != REG_SIZE; ++i) {
		champ->tmp += 1;
		nbr_to_load += my_getnbr(*champ->tmp);
		nbr_to_load *= 10;
	}
	if (rg > REG_NUMBER)
		return;
	champ->registers[rg] = nbr_to_load;
	champ->carry = modif_carry(champ->carry);
}

void lldi_instru(instructions *instr, champions *champ, circular_memory *vm)
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
