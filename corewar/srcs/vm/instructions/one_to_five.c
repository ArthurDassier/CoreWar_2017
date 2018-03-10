/*
** EPITECH PROJECT, 2018
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void live_instru(circular_memory *vm, champions *champ, int types)
{
	(void) champ;
	(void) vm;
	(void) types;
//	my_printf("Le joueur %d (?) est en vie.\n", instr->arg1);
}

void ld_instru(circular_memory *vm, champions *champ, int types)
{
	int	ld = 0;
	int	rg = 0;
	int	nbr_to_load = 0;

	(void) vm;
	ld = getnbr_from_size(champ, types / 10);
	rg = getnbr_from_size(champ, types % 10);
	champ->PC = champ->tmp;
	champ->tmp = champ->PC + ld % IDX_MOD;
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->tmp = champ->PC;
	if (rg > REG_NUMBER)
		return;
	champ->registers[rg] = nbr_to_load;
}

void st_instru(circular_memory *vm, champions *champ, int types)
{
	(void) champ;
	(void) vm;
	(void) types;
}

void add_instru(circular_memory *vm, champions *champ, int types)
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
	champ->registers[r3 - 1] = r1 + r2;
	champ->carry = modif_carry(champ->carry);
}

void sub_instru(circular_memory *vm, champions *champ, int types)
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
	champ->registers[r3 - 1] = r1 - r2;
	champ->carry = modif_carry(champ->carry);
}
