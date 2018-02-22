/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** parseur for asm
*/
#include "corewar.h"

void	swap_endian(union endian *result)
{
	char	tmp;

	tmp = result->byte[3];
	result->byte[3] = result->byte[0];
	result->byte[0] = tmp;
	tmp = result->byte[2];
	result->byte[2] = result->byte[1];
	result->byte[1] = tmp;
}

void	parser(struct d_queue *head, int fd)
{
	struct	d_queue	*tmp = head->next;
	struct	token	*token;

	add_header(head, fd);
	while (tmp != NULL) {
		token = tmp->token;
		error_handling(token, head);
		add_cmd(tmp, fd);
		add_adressage(tmp, fd);
		add_param(tmp, fd);
		tmp = tmp->next;
	}
}