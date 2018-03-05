/*
** EPITECH PROJECT, 2018
** label.c
** File description:
** functions to handle labels
*/
#include "corewar.h"

static struct d_queue	*get_label(char *label, struct d_queue *head)
{
	struct d_queue	*tmp = head;
	struct token	*token = tmp->token;

	while (tmp != NULL && my_strcmp(token->mnemo, label) != 0) {
		token = tmp->token;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

void	labels(struct d_queue *head, int fd, int i, struct token *token)
{
	union endian	result;
	int		curr = token->l_size;
	struct d_queue	*tmp = get_label(token->arg_tab[i].args + 2, head);
	struct	token	*tmp_tk = tmp->token;

	if (tmp == NULL)
		return;
	result.val = tmp_tk->l_size - curr;
	swap_endian(&result);
	if (my_strcmp(token->mnemo, "live") == 0) {
		write(fd, &result, 4);
	} else if (check_case(token->mnemo) == true) {
		result.val = result.val >> 16;
		write(fd, &result, IND_SIZE);
	} else {
		write(fd, &result, DIR_SIZE);
	}
}