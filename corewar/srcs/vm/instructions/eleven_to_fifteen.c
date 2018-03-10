/*
** EPITECH PROJECT, 2018
** eleven_to_fifteen.c
** File description:
** Arthur
*/

#include "virtual.h"

void sti_instru(circular_memory *vm, champions *champ, int types)
{
	int	rr = getnbr_from_size(champ, types / 100);
	int	rg = getnbr_from_size(champ, types / 10 % 10);
	int	ld = getnbr_from_size(champ, types % 10);
	int	i = 0;
	char	*str = NULL;

	champ->PC = champ->tmp;
	if (rr > REG_NUMBER)
		return;
	str = its(champ->registers[rr - 1]);
	champ->tmp += (rg + ld) % IDX_MOD;
	memory_put_move(vm, champ, str[i++], 0);
	while (str[i] != '\0')
		memory_put_move(vm, champ, str[i++], 1);
	champ->tmp = champ->PC;
}

void fork_instru(circular_memory *vm, champions *champ, int types)
{
	(void) champ;
	(void) vm;
	(void) types;
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

	(void) vm;
	ld = getnbr_from_size(champ, types / 10);
	rg = getnbr_from_size(champ, types % 10);
	champ->PC = champ->tmp;
	champ->tmp += ld;
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->tmp = champ->PC;
	if (rg > REG_NUMBER)
		return;
	champ->registers[rg - 1] = nbr_to_load;
}

void lldi_instru(circular_memory *vm, champions *champ, int types)
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
	if (rg > REG_NUMBER)
		return;
	champ->tmp += ld;
	the_s = getnbr_from_size(champ, IND_SIZE) + nbr;
	champ->tmp = champ->PC + the_s;
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->registers[rg - 1] = nbr_to_load;
	champ->tmp = champ->PC;
	champ->carry = modif_carry(champ->carry);
}

void lfork_instru(circular_memory *vm, champions *champ, int types)
{
	(void) types;
	(void) champ;
	(void) vm;
	/*It creates a new program that inherits different states from
	the parent. This program is executed at the address PC
	+ first index_one.*/
	return;
}
