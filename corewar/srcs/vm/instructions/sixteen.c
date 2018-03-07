/*
** EPITECH PROJECT, 2017
** sixteen.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void aff(instructions *instr, champions *champ, circular_memory *vm)
{
	my_printf("%c\n", instr->arg1);
}

int modif_carry(int carry)
{
	if (carry == 0)
		carry = 1;
	else
		carry = 0;
	return (carry);
}
