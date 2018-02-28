/*
** EPITECH PROJECT, 2017
** instructions_six_ten.c
** File description:
** instr_six_ten
*/

#include "data_base.h"

int and_instruction(instructions *list, int fd)
{
	union endian	tmp;

	read(fd, &list->adr, 1);
	list->mnemonique = "AND";
	read(fd, &list->arg1, 1);
	read(fd, &list->arg2, 4);
	tmp.val = list->arg2;
	switch_endian_four(&tmp);
	list->arg2 = tmp.val;
	read(fd, &list->arg3, 1);
	list->nb_cycles = 6;
	return (0);
}

int or_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "OR";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 6;
	return (0);
}

int xor_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "XOR";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 6;
	return (0);
}

int zjmp_instruction(instructions *list, int fd)
{
	union endian	tmp;

	list->mnemonique = "ZJMP";
	read(fd, &list->arg1, 2);
	tmp.val = list->arg1;
	switch_endian_two(&tmp);
	list->arg1 = tmp.val;
	list->nb_cycles = 25;
	return (0);
}

int ldi_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "LDI";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 25;
	return (0);
}