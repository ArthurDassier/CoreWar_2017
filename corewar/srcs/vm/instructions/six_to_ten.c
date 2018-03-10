/*
** EPITECH PROJECT, 2018
** six_to_ten.c
** File description:
** Arthur
*/

#include "virtual.h"

void and_instru(circular_memory *vm, champions *champ, int types)
{
	int	r1 = 0;
	int	r2 = 0;
	int	r3 = 0;

	(void) vm;
	r1 = getnbr_from_size(champ, types / 100);
	r2 = getnbr_from_size(champ, types / 10 % 10);
	r3 = getnbr_from_size(champ, types % 10);
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = champ->registers[r1 - 1] & champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
}

void or_instru(circular_memory *vm, champions *champ, int types)
{
	int	r1 = 0;
	int	r2 = 0;
	int	r3 = 0;

	(void) vm;
	r1 = getnbr_from_size(champ, types / 100);
	r2 = getnbr_from_size(champ, types / 10 % 10);
	r3 = getnbr_from_size(champ, types % 10);
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = champ->registers[r1 - 1] | champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
}

void xor_instru(circular_memory *vm, champions *champ, int types)
{
	int	r1 = 0;
	int	r2 = 0;
	int	r3 = 0;

	(void) vm;
	r1 = getnbr_from_size(champ, types / 100);
	r2 = getnbr_from_size(champ, types / 10 % 10);
	r3 = getnbr_from_size(champ, types % 10);
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = champ->registers[r1 - 1] ^ champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
}

void zjmp_instru(circular_memory *vm, champions *champ, int types)
{
	int	jump = 0;

	(void) vm;
	if (champ->carry == 1) {
		jump = getnbr_from_size(champ, types) % IDX_MOD;
		champ->PC += jump;
		champ->tmp = champ->PC;
	}
}

void ldi_instru(circular_memory *vm, champions *champ, int types)
{
	int	ld = 0;
	int	nbr = 0;
	int	rg = 0;
	int	the_s = 0;
	int	nbr_to_load = 0;

	(void) vm;
	ld = getnbr_from_size(champ, types / 100);
	nbr = getnbr_from_size(champ, types / 10 % 10);
	rg = getnbr_from_size(champ, types % 10);
	champ->PC = champ->tmp;
	champ->tmp = champ->PC + ld % IDX_MOD;
	the_s = getnbr_from_size(champ, IND_SIZE) + nbr;
	champ->tmp = champ->PC + the_s % IDX_MOD;
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	if (rg > REG_NUMBER)
		return;
	champ->registers[rg - 1] = nbr_to_load;
	champ->tmp = champ->PC;
}
