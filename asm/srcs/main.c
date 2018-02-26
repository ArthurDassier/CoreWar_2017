/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "corewar.h"

static void usage(void)
{
	my_printf("USAGE\n"
		"\t./asm file_name[.s]\n\n"
		"DESCRIPTION\n"
		"\tfile_name\tfile in assembly language to be converted into"
		" file_name.core, an\n\t\t\texecutable in the Virtual Machine."
		"\n");
	exit(0);
}

static int process_arg(int ch)
{
	if (ch == 'h')
		usage();
	if (ch == '?')
		return (-1);
	return (0);
}

int main(int ac, char **av)
{
	int	ch = 0;
	struct d_queue	*dq = NULL;
	header_t	*head = NULL;
	struct token	*tmp;

	while ((ch = my_getopt(ac, av, "h")) != -1)
		if (process_arg(ch) < 0)
			return (84);
	if (my_optind == 0)
		return (84);
	for (int i = my_optind; i < ac; i++) {
		dq = lex_file(av[i]);
		head = dq->token;
		printf("--------------------\n"
			"magic: %d\n"
			"prog_name: %s\n"
			"comment: %s\n", head->magic, head->prog_name, head->comment);
		dq = dq->next;
		while (dq != NULL) {
			tmp = dq->token;
			printf("---------------------------\n"
				"%s:%d\n"
				"mnemo: %s\n", (tmp->tk_val == L) ? "LABEL" : "INSTRUCTION", tmp->l_size,
				tmp->mnemo);
			for (int i = 0; tmp->arg != NULL && tmp->arg[i]; i++)
				printf("arg[%d]: %s -> %d\n", i, tmp->arg[i], tmp->tk_name[i]);
			dq = dq->next;
		}
	}
	return (0);
}
