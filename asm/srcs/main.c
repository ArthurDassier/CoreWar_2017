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

static char	*get_name(char *av)
{
	int	index;
	char	*name = malloc(sizeof(*name) * my_strlen(av) + 9);

	if (name == NULL)
		return (NULL);
	for (index = 0; av[index] != '.'; ++index);
	my_strncpy(name, av, index);
	my_strcat(name, "cor");
	return (name);
}

int main(int ac, char **av)
{
	int		ch = 0;
	int		fd = 0;
	struct d_queue	*dq = NULL;

	while ((ch = my_getopt(ac, av, "h")) != -1)
		if (process_arg(ch) < 0)
			return (FAILURE);
	if (my_optind == 0)
		return (FAILURE);
	for (int i = my_optind; i < ac; i++) {
		char *new = get_name(av[i]);
		fd = open(new, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dq = lex_file(av[i]);
		if (dq == NULL)
			continue;
		parser(dq, fd);
	}
	return (SUCCESS);
}
