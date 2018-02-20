/*
** EPITECH PROJECT, 2017
** lex.c
** File description:
** lexer file
*/

#include "corewar.h"

static struct token *process_line(char *line)
{
	struct token	*node = malloc(sizeof(struct token));

	if (node == NULL)
		malloc_error();
	if (is_line_comment(line))
		return (NULL);
	return (node);
}

struct d_queue *lex_file(char *fname)
{
	struct d_queue	*tmp = NULL;
	struct token	*node = NULL;
	int		fd = open(fname, O_RDONLY);
	char		*line = (char *)malloc(sizeof(char) * BUFSIZ);

	if (fd < 0)
		return (file_error(fname));
	line = my_fgets(line, BUFSIZ, fd);
	while (line) {
		node = process_line(line);
		if (node != NULL) {
			printf("%s\n", line);
			tmp = add_d_queue(tmp, (void *)node);
		}
		line = my_fgets(line, BUFSIZ, fd);
	}
	close(fd);
	return (tmp);
}