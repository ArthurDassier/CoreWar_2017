/*
** EPITECH PROJECT, 2018
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void live_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) champ;
	(void) vm;
	my_printf("Le joueur %d (?) est en vie.\n", instr->arg1);
}

void ld_instru(circular_memory *vm, champions *champ, int types)
{
	int	ld = 0;
	int	rg = 0;
	int	nbr_to_load = 0;

	ld = name(champ, types / 10);
	rg = name(champ, types % 10);
	champ->tmp = (champ->PC + ld % IDX_MOD) - 1;
	nbr_to_load = name(champ, REG_SIZE);
	if (rg > REG_NUMBER)
		return;
	champ->registers[rg] = nbr_to_load;
}

void st_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	int	i = 0;
	char	*str = its(instr->arg1);

	if (instr->arg2 > REG_NUMBER) {
		champ->tmp = champ->PC + instr->arg2 % IDX_MOD;
		memory_put_move(vm, champ, str[i++], 0);
		while (str[i] != '\0')
			memory_put_move(vm, champ, str[i++], 1);
		champ->tmp = champ->PC;
	} else
		instr->arg2 = instr->arg1;
}

void add_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg3 = instr->arg1 + instr->arg2;
	champ->carry = modif_carry(champ->carry);
}

void sub_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) vm;
	instr->arg3 = instr->arg1 - instr->arg2;
	champ->carry = modif_carry(champ->carry);
}
