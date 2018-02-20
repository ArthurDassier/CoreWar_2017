/*
** EPITECH PROJECT, 2018
** adressage.c
** File description:
** functions to do the adressage
*/
#include "corewar.h"

static int	adressage(struct token *token)
{
	int	result = 0;

	result = result << 2;
	for (int i = 0; i < token->arg_no; ++i) {
		if (token->arg_tab[i].tk_name == REG) {
			result += 1;
			result = result << 2;
		}
		if (token->arg_tab[i].tk_name == DRT) {
			result += 2;
			result = result << 2;
		}
		if (token->arg_tab[i].tk_name == IND) {
			result += 3;
			result = result << 2;
		}
	}
	return (result);
}

void	add_adressage(struct d_queue *head, int fd)
{
	struct	token	*token = head->token;
	int		result;

	result = adressage(token);
	write(fd, &result, 1);
}