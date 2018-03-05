/*
** EPITECH PROJECT, 2017
** init_vm.c
** File description:
** Arthur
*/

#include "my.h"

<<<<<<< HEAD:corewar/srcs/vm/recup_instruct/fill_av.c
void fill_arg(arguments *argv, char *flag, char *parameter)
{
	if (flag[1] == 'a') {
		argv->on_a = ON;
		argv->flg_a = parameter;
	} else if (flag[1] == 'n') {
		argv->on_n = ON;
		argv->flg_n = parameter;
	} else {
		argv->on_dump = ON;
		argv->flg_dump = parameter;
	}
}

arguments *fill_av(char **av, arguments *argv)
=======
arguments *init_vm(char **av, arguments *argv)
>>>>>>> df9e369b55499313fdf677a2db184ab8ee7ebd9f:corewar/srcs/vm/recup_instruct/init_vm.c
{
	(void) av;
	return (argv);
}
