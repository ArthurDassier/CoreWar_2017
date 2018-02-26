/*
** EPITECH PROJECT, 2017
** mem.c
** File description:
** <..>
*/

#include "corewar.h"

static int is_exception(struct token *node)
{
	char	*name[5] = { "live", "zjmp", "fork", "lfork", NULL };

	for (int i = 0; name[i]; i++) {
		if (!my_strcmp(node->mnemo, name[i]))
			return (1);
	}
	return (0);
}

static int add_arg(struct token *node)
{
	int	no = 0;

	for (int i = 0; i < node->arg_no && node->arg[i]; i++) {
		if (node->tk_name[i] == REG)
			no += REG_SIZE;
		if (node->tk_name[i] == DRT)
			no += DIR_SIZE;
		if (node->tk_name[i] == IND)
			no+= IND_SIZE;
		if (node->tk_name[i] == LAB)
			no += DIR_SIZE;
	}
	return (no);
}

void set_mem(struct token *node)
{
	static int	curent_pos = 0;

	if (node == NULL)
		return;
	node->l_size = curent_pos;
	curent_pos += INSTRUCT_SIZE;
	if (is_exception(node))
		curent_pos += 8;
	else
		curent_pos += add_arg(node);
}
