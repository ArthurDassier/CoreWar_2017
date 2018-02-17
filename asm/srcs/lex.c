/*
** EPITECH PROJECT, 2017
** lex.c
** File description:
** <..>
*/

#include "corewar.h"

struct d_queue *lex_file(char *fname)
{
	struct d_queue	*tmp = NULL;
	int		fd = open(fname, O_RDONLY);
	char		*line = NULL;

	if (fd < 0)
		return (file_error(fname));
	line = get_next_line(fd);
	while (line) {
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (tmp);
}
