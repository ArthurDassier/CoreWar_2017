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
	r2 = getnbr_from_size(champ, types % 100);
	r3 = getnbr_from_size(champ, types % 10);

	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = r1 & r2;
	champ->carry = modif_carry(champ->carry);
}

void or_instru(circular_memory *vm, champions *champ, int types)
{
	int	r1 = 0;
	int	r2 = 0;
	int	r3 = 0;

	(void) vm;
	r1 = getnbr_from_size(champ, types / 100);
	r2 = getnbr_from_size(champ, types % 100);
	r3 = getnbr_from_size(champ, types % 10);

	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = r1 | r2;
	champ->carry = modif_carry(champ->carry);
}

void xor_instru(circular_memory *vm, champions *champ, int types)
{
	int	r1 = 0;
	int	r2 = 0;
	int	r3 = 0;

	(void) vm;
	r1 = getnbr_from_size(champ, types / 100);
	r2 = getnbr_from_size(champ, types % 100);
	r3 = getnbr_from_size(champ, types % 10);

	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = r1 ^ r2;
	champ->carry = modif_carry(champ->carry);
}

void zjmp_instru(circular_memory *vm, champions *champ, int types)
{
	(void) champ;
	(void) vm;
	(void) types;
}

void ldi_instru(circular_memory *vm, champions *champ, int types)
{
	(void) champ;
	(void) vm;
	(void) types;
}
