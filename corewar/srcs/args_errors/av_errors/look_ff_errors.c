/*
** EPITECH PROJECT, 2017
** look_ff_errors.c
** File description:
** Arthur
*/

#include "my.h"

int lf_flag_err(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i, int nb_hyp)
{
	if (!av[i + 1] || (nb_hyp = send_to_flag_handler(flag_handler,
	nb_hyp, av, i)) == 84) {
		put_compil_error();
		return (84);
	}
	return (nb_hyp);
}
