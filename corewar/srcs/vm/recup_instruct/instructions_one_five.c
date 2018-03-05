/*
** EPITECH PROJECT, 2017
** instructions_one_five.c
** File description:
** instr_one_five
*/

#include "virtual.h"

int live_instruction(instructions *list, int fd)
{
	union endian	tmp;

	list->mnemonique = "1";
	read(fd, &list->arg1, 4);
	tmp.val = list->arg1;
	switch_endian_four(&tmp);
	list->arg1 = tmp.val;
	list->nb_cycles = 10;
	return (0);
}

int ld_instruction(instructions *list, int fd)
{
	union endian	tmp;

	read(fd, &list->adr, 1);
	list->mnemonique = "2";
	read(fd, &list->arg1, 4);
	tmp.val = list->arg1;
	switch_endian_four(&tmp);
	list->arg1 = tmp.val;
	read(fd, &list->arg2, 1);
	list->nb_cycles = 5;
	return (0);
}

int st_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "3";
	if (read_parameters(list, list->adr, 2, fd) != 0)
		return (-1);
	list->arg3 = 0;
	list->nb_cycles = 5;
	return (0);
}

int add_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "4";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 10;
	return (0);
}

int sub_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "5";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 10;
	return (0);
}
