/*
** EPITECH PROJECT, 2018
** sixteen.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void aff_instru(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) champ;
	(void) vm;
	my_printf("%c\n", instr->arg1);
}

int modif_carry(int carry)
{
	if (carry == 0)
		return (1);
	else
		return (0);
}
