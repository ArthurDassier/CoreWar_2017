/*
** EPITECH PROJECT, 2018
** parameters.c
** File description:
** functions to add parameters to .cor
*/
#include "corewar.h"

static	void	(*param_tab[NB_INS])(struct token *, int, int) = {
	&registers,
	&directs,
	&indirects
};

bool	check_case(char *str)
{
	if (my_strcmp(str, "zjump") == 0 || my_strcmp(str, "ldi") == 0 ||
	my_strcmp(str, "sti") == 0 || my_strcmp(str, "sti") == 0)
		return (true);
	return (false);
}

void	registers(struct token *token, int fd, int i)
{
	int	result = 0;

	result = my_getnbr(token->arg_tab[i].args + 1);
	write(fd, &result, 1);
}

void	directs(struct token *token, int fd, int i)
{
	union endian	result;

	if (token->arg_tab[i].args[1] != LABEL_CHAR) {
		result.val = my_getnbr(token->arg_tab[i].args + 1);
		swap_endian(&result);
		if (my_strcmp(token->mnemo, "live") == 0)
			write(fd, &result, 4);
		else if (check_case(token->mnemo) == true) {
			result.val = result.val >> 16;
			write(fd, &result, IND_SIZE);
		}
		else
			write(fd, &result, DIR_SIZE);
	}
}

void	indirects(struct token *token, int fd, int i)
{
	union endian	result;

	result.val = my_getnbr(token->arg_tab[i].args + 1);
	result.val = result.val << 16;
	swap_endian(&result);
	write(fd, &result, IND_SIZE);
}

void	add_param(struct d_queue *head, int fd)
{
	struct token *token = head->token;

	for (int i = 0; i < token->arg_no; ++i) {
		if (token->arg_tab[i].tk_name == LAB) {
			labels(head, fd, i);
			++i;
		}
		param_tab[token->arg_tab[i].tk_name](token, fd, i);
	}
}