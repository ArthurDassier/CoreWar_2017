/*
** EPITECH PROJECT, 2017
** instructions_ele_fif.c
** File description:
** instr_ele_fif
*/

#include "virtual.h"

int sti_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "B";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 25;
	return (0);
}

int fork_instruction(instructions *list, int fd)
{
	union endian	tmp;

	list->mnemonique = "C";
	read(fd, &list->arg1, 2);
	tmp.val = list->arg1;
	switch_endian_two(&tmp);
	list->arg1 = tmp.val;
	list->nb_cycles = 800;
	return (0);
}

int lld_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "D";
	if (read_parameters(list, list->adr, 2, fd) != 0)
		return (-1);
	list->nb_cycles = 10;
	return (0);
}

int lldi_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "E";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 50;
	return (0);
}

int lfork_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "F";
	if (read_parameters(list, list->adr, 1, fd) != 0)
		return (-1);
	list->nb_cycles = 1000;
	return (0);
}
