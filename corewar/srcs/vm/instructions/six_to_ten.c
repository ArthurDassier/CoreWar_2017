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

void zjmp_instru(circular_memory *vm, champions *champ, int types)
{
	int	nbr = 0;
	int	ld = 0;

	for (int i = 0; i != types / 10; ++i) {
		champ->tmp = champ->PC + i;
		ld += my_getnbr(*champ->tmp);
		ld *= 10;
	}
	if (champ->carry == 1) {
		for (int i = 0; i != IND_SIZE; ++i) {
			champ->tmp = champ->PC + i;
			nbr += my_getnbr(*champ->tmp);
			nbr *= 10;
		}
		champ->PC = champ->PC + nbr % IDX_MOD;
		champ->tmp = champ->PC;
	}
}

void ldi_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	int	S = 0;

	(void) vm;
	champ->tmp = champ->PC + instr->arg1 % IDX_MOD;
	for (int i = 0; i != IND_SIZE; ++i) {
		S += my_getnbr(champ->tmp);
		S *= 10;
		++champ->tmp;
	}
	S += instr->arg2;
	champ->tmp = champ->PC + S % IDX_MOD;
	instr->arg3 = 0;
	for (int i = 0; i != REG_SIZE; ++i) {
		instr->arg3 += my_getnbr(champ->tmp);
		instr->arg3 *= 10;
		++champ->tmp;
	}
	champ->tmp = champ->PC;
}
