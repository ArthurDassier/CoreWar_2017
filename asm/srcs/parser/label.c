/*
** EPITECH PROJECT, 2018
** label.c
** File description:
** functions to handle labels
*/
#include "corewar.h"

static struct d_queue	*does_label_exists(char *label, struct d_queue *head)
{
	struct d_queue	*tmp = head;
	struct token	*token = head->token;

	while (tmp != NULL && my_strcmp(token->mnemo, label) != 0) {
		token = tmp->token;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (FAILURE);
	return (tmp);
}

void	add_label(struct d_queue *head, int fd)
{
	struct token	*token = (head->next)->token;
	struct d_queue	*tmp = does_label_exists();

	calculate_mem();
	write();
}