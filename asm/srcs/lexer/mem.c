/*
** EPITECH PROJECT, 2017
** mem.c
** File description:
** <..>
*/

#include "corewar.h"

static int is_exception(struct token *node)
{
	char	*name[2] = { "live", NULL };

	for (int i = 0; name[i]; i++) {
		if (!my_strcmp(node->mnemo, name[i]))
			return (1);
	}
	return (0);
}
static int is_index(struct token *node)
{
	char	*name[7] = { "ld", "st", "ldi", "sti", NULL };

	for (int i = 0; name[i]; i++) {
		if (!my_strcmp(node->mnemo, name[i]))
			return (1);
	}
	return (0);
}

static int is_index_only(struct token *node)
{
	char	*name[4] = { "zjmp", "fork", NULL };

	for (int i = 0; name[i]; i++) {
		if (!my_strcmp(node->mnemo, name[i]))
			return (1);
	}
	return (0);
}

int add_arg(struct token *node)
{
	int	no = 0;

	for (int i = 0; i < node->arg_no; i++) {
		if (is_index_only(node)) {
			no += 2;
			continue;
		}
		if (is_index(node) && node->arg_tab[i].tk_name != REG) {
			no += 2;
			continue;
		}
		if (node->arg_tab[i].tk_name == REG)
			no += T_REG;
		if (node->arg_tab[i].tk_name == DRT)
			no += DIR_SIZE;
		if (node->arg_tab[i].tk_name == IND)
			no+= IND_SIZE;
		if (node->arg_tab[i].tk_name == LAB)
			no += T_LAB;
	}
	return (no);
}

int set_mem(struct token *node)
{
	static int	curent_pos = 0;
	int		no = 0;

	if (node == NULL || node->tk_val == L)
		return (0);
	node->l_size = curent_pos;
	curent_pos += INSTRUCT_SIZE;
	no += INSTRUCT_SIZE;
	if (is_exception(node)) {
		curent_pos += 4;
		no += 4;
	} else {
		no += add_arg(node);
		no += (is_index_only(node)) ? 0 : 1;
		curent_pos += add_arg(node);
		curent_pos += (is_index_only(node)) ? 0 : 1;
	}
	return (no);
}
