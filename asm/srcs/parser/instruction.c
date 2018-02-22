/*
** EPITECH PROJECT, 2018
** instruction.c
** File description:
** functions for the instructions
*/
#include "corewar.h"

int	get_cmd(char *cmd)
{
	if (cmd == NULL)
		return (FAILURE);
	for (int i = 0; op_tab[i].mnemonique != NULL; ++i) {
		if (my_strcmp(cmd, op_tab[i].mnemonique) == 0)
			return (i);
	}
	return (FAILURE);
}

void	add_cmd(struct d_queue *head, int fd)
{
	struct	token	*token = head->token;
	int	index = get_cmd(token->mnemo);

	if (index != FAILURE)
		write(fd, &(op_tab[index].code), 1);
}