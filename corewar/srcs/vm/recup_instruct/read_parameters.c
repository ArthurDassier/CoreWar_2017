/*
** EPITECH PROJECT, 2017
** read_parameters.c
** File description:
** check_all_params
*/

#include "data_base.h"

int read_value_of_param(int val, int fd)
{
	int		arg = 0;
	union endian	ins;

	if (val == 1) {
		if (read(fd, &arg, 1) == -1)
			return (-1);
		return (arg);
	} else if (val == 2) {
		if (read(fd, &arg, 2) == -1)
			return (-1);
		ins.val = arg;
		switch_endian_two(&ins);
		return (ins.val);
	} else {
		if (read(fd, &arg, 4) == -1)
			return (-1);
		ins.val = arg;
		switch_endian_four(&ins);
		return (ins.val);
	}
	return (0);
}

int read_in_struct(instructions *list, int val, int j, int fd)
{
	if (j == 0) {
		list->arg1 = 0;
		if ((list->arg1 = read_value_of_param(val, fd)) == -1)
			return (-1);
	} else if (j == 1) {
		list->arg2 = 0;
		if ((list->arg2 = read_value_of_param(val, fd)) == -1)
			return (-1);
	} else {
		list->arg3 = 0;
		if ((list->arg3 = read_value_of_param(val, fd)) == -1)
			return (-1);
	}
	return (0);
}

int read_parameters(instructions *list, int code, int nb_arg, int fd)
{
	int	bin = 0;
	int	loop = 0;
	int	val = 0;
	int	i = 0;

	if (nb_arg == 2) {
		++nb_arg;
		loop = 1;
	}
	while (nb_arg != loop) {
		val = (code >> nb_arg * 2) ^ bin;
		if (read_in_struct(list, val, i++, fd) == -1)
			return (-1);
		bin |= code >> (nb_arg * 2);
		bin <<= 2;
		--nb_arg;
	}
	return (0);
}
