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
	champ->tmp += ld % IDX_MOD;
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->tmp = champ->PC;
	if (rg > REG_NUMBER)
		return;
	champ->registers[rg - 1] = nbr_to_load;
}

void st_instru(circular_memory *vm, champions *champ, int types)
{
	int	rg = getnbr_from_size(champ, types / 10);
	int	ld = getnbr_from_size(champ, types % 10);
	int	i = 0;
	char	*str = NULL;

	champ->PC = champ->tmp;
	str = its(champ->registers[rg - 1]);
	if (types % 10 == 8) {
		champ->tmp += ld % IDX_MOD;
		memory_put_move(vm, champ, str[i++], 0);
		while (str[i] != '\0')
			memory_put_move(vm, champ, str[i++], 1);
		champ->tmp = champ->PC;
	} else {
		champ->registers[rg - 1] = champ->registers[ld - 1];
		champ->tmp = champ->PC;
	}
	free(str);
}

void add_instru(circular_memory *vm, champions *champ, int types)
{
	int	r1 = getnbr_from_size(champ, types / 100);
	int	r2 = getnbr_from_size(champ, types / 10 % 10);
	int	r3 = getnbr_from_size(champ, types % 10);

	(void) vm;
	champ->PC = champ->tmp;
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = champ->registers[r1 - 1]
	+ champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
}

void sub_instru(circular_memory *vm, champions *champ, int types)
{
	int	r1 = getnbr_from_size(champ, types / 100);
	int	r2 = getnbr_from_size(champ, types / 10 % 10);
	int	r3 = getnbr_from_size(champ, types % 10);

	(void) vm;
	champ->PC = champ->tmp;
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return;
	champ->registers[r3 - 1] = champ->registers[r1 - 1]
	- champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
}
