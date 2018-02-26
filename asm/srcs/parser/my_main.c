/*
** EPITECH PROJECT, 2018
** my_main.c
** File description:
** my _main function
*/
#include "corewar.h"

struct d_queue	*fill_list(void)
{
	struct token *node = malloc(sizeof(*node));
	struct d_queue	*head = NULL;
	struct header_s	*header = malloc(sizeof(*header));
	char		*name = "test";
	char		*comment = "It's a test file";

	header->magic = COREWAR_EXEC_MAGIC;
	my_strcpy(header->prog_name, name);
	header->prog_size = 42;
	my_strcpy(header->comment, comment);
	head = add_d_queue(head, (void *)header);
	node->tk_val = I;
	node->mnemo = "sti";
	node->arg_no = 3;
	node->arg_tab = malloc(sizeof(*(node->arg_tab)) * 3);
	node->arg_tab[0].args = "r1";
	node->arg_tab[0].tk_name = REG;
	node->arg_tab[1].args = "%:live";
	node->arg_tab[1].tk_name = DRT;
	node->arg_tab[2].args = "%1";
	node->arg_tab[2].tk_name = DRT;
	node->line = 1;
	head = add_d_queue(head, (void *)node);
	node = malloc(sizeof(*node));
	node->tk_val = I;
	node->mnemo = "and";
	node->arg_no = 3;
	node->arg_tab = malloc(sizeof(*(node->arg_tab)) * 3);
	node->arg_tab[0].args = "r1";
	node->arg_tab[0].tk_name = REG;
	node->arg_tab[1].args = "%0";
	node->arg_tab[1].tk_name = DRT;
	node->arg_tab[2].args = "r1";
	node->arg_tab[2].tk_name = REG;
	node->line = 2;
	head = add_d_queue(head, (void *)node);
	return (head);
}

int	main(int ac, char **av)
{
	struct d_queue *head = NULL;
	int fd = open("test.cor", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	(void)ac;
	(void)av;
	head = fill_list();
	parser(head, fd);
	return (0);
}