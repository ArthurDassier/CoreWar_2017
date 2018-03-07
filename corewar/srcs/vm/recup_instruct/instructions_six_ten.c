/*
** EPITECH PROJECT, 2017
** instructions_six_ten.c
** File description:
** instr_six_ten
*/

#include "virtual.h"

int and_instruction(instructions *list, int fd)
{
	union endian	tmp;

	read(fd, &list->adr, 1);
	list->mnemonique = "6";
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
	list->mnemonique = "7";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 6;
	return (0);
}

int xor_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "8";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 6;
	return (0);
}

int zjmp_instruction(instructions *list, int fd)
{
	union endian	tmp;

	list->mnemonique = "9";
	read(fd, &list->arg1, 2);
	tmp.val = list->arg1;
	switch_endian_two(&tmp);
	list->arg1 = tmp.val;
	list->nb_cycles = 25;
	list->types = 400;
	return (0);
}

int ldi_instruction(instructions *list, int fd)
{
	printf("%x\n", list->adr);
	read(fd, &list->adr, 1);
	printf("%X\n", list->adr);
	list->mnemonique = "A";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 25;
	return (0);
}
