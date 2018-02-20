/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** parseur for asm
*/
#include "corewar.h"

void	parser(struct d_queue *head, int fd)
{
	struct	d_queue	*tmp = head;
	struct token	*token;

	while (tmp != NULL) {
		token = tmp->token;
		add_cmd(head, fd);
		add_adressage(head, fd);
		add_param(head, fd);
		tmp = tmp->next;
	}
}