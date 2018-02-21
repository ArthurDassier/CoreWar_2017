/*
** EPITECH PROJECT, 2017
** lex.c
** File description:
** lexer file
*/

#include "corewar.h"

static struct token *process_line(char *line, int line_no, char *fname)
{
	struct token	*node = malloc(sizeof(struct token));

	if (node == NULL)
		malloc_error();
	if (is_line_comment(line)) {
		free(node);
		return (NULL);
	}
	node->line = line_no;
	if (is_label(line)) {
		node->tk_val = L;
		node->mnemo = my_strdup(line);
		node->l_size = 0;
	} else {
		node = error_invalid_instruct(fname, line_no);
	}
	return (node);
}

struct d_queue *lex_file(char *fname)
{
	struct d_queue	*tmp = NULL;
	struct token	*node = NULL;
	int		fd = open(fname, O_RDONLY);
	char		*line = NULL;
	int		line_no = 0;

	if (fd < 0)
		return (file_error(fname));
	line = get_next_line(fd);
	while (line) {
		line_no++;
		node = process_line(line, line_no, fname);
		if (node != NULL) {
			printf("%s:%d\n", line, is_header(line));
			tmp = add_d_queue(tmp, (void *)node);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (tmp);
}
