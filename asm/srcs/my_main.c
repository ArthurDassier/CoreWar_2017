/*
** EPITECH PROJECT, 2018
** my_main.c
** File description:
** my _main function
*/
#include "corewar.h"

struct d_queue	*fill_list()
{
	struct token *node = malloc(sizeof(*node));
	struct d_queue	*head = NULL;

	node->tk_val = I;
	node->mnemo = "live";
	node->arg_no = 1;
	node->line = 0;
	head = add_d_queue(head, (void *)node);
	return (head);
}

int	main(int ac, char **av)
{
	struct d_queue *head = NULL;

	(void)ac;
	(void)av;
	head = fill_list();
	add_cmd(head);
	return (0);
}