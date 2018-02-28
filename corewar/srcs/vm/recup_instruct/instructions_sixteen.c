/*
** EPITECH PROJECT, 2017
** instructions_one_five.c
** File description:
** instr_one_five
*/

#include "data_base.h"

int aff_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "10";
	if (read_parameters(list, list->adr, 1, fd) != 0)
		return (-1);
	list->nb_cycles = 2;
	return (0);
}
