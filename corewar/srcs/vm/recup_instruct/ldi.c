/*
** EPITECH PROJECT, 2017
** ldi.c
** File description:
** ldi_inst
*/

#include "virtual.h"

int read_for_ldi(instructions *list, int val, int i, int fd)
{
	union endian	tmp;

	if (i == 0) {
		if (val != 1) {
			read(fd, &list->arg1, IND_SIZE);
			tmp.val = list->arg1;
			switch_endian_two(&tmp);
			list->arg1 = tmp.val;
			list->types = 4;
		} else
			i = 2;
	} else if (i == 1) {
		if (val != 1) {
			read(fd, &list->arg2, IND_SIZE);
			tmp.val = list->arg2;
			switch_endian_two(&tmp);
			list->arg2 = tmp.val;
			list->types = list->types * 10 + 4;
		} else
			i = 2;
	}
	if (i == 2) {
		if (val != 1)
			return (-1);
		else
			read(fd, &list->arg3, T_REG);
		list->types = list->types * 10 + 2;
	}
	return (0);
}

int read_ldi(instructions *list, int code, int nb_arg, int fd)
{
	int	val = 0;
	int	bin = 0;
	int	i = 0;

	while (nb_arg != 0) {
		val = (code >> nb_arg * 2) ^ bin;
		if (read_for_ldi(list, val, i++, fd) == -1)
			return (-1);
		bin |= code >> (nb_arg * 2);
		bin <<= 2;
		--nb_arg;
	}
	return (0);
}
