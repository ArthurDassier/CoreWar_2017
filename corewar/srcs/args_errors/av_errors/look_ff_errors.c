/*
** EPITECH PROJECT, 2017
** look_ff_errors.c
** File description:
** Arthur
*/

#include "my.h"

int lf_flag_err(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i)
{
	if (!av[i][1]) {
		my_puterror("Error in function open: No such file or directory.\n");
		return (84);
	}
	if (g_flag(av[i]) == 84)
		return (84);
	if (!av[i + 1]) {
		my_puterror("Invalid option.\n");
		return (84);
	}
	if (send_to_flag_handler(flag_handler, av, i) == 84)
		return (84);
	return (0);
}
