/*
** EPITECH PROJECT, 2017
** lex.c
** File description:
** lexer file
*/

#include "corewar.h"

static struct token *proccess_label(char *line ,int *pos, struct token *node)
{
	while ((line[*pos] == ' ' || line[*pos] == '\t') && line[*pos] != '\0')
		*pos += 1;
	node->tk_val = L;
	node->mnemo = my_strndup(line + *pos, is_label(line + *pos));
	node->l_size = 0;
	*pos += is_label(line + *pos) + 1;
	node->arg = NULL;
	node->arg_no = 0;
	return (node);
}

static struct token *proccess_mnemonique(char *line ,struct token *node,
		int *pos)
{
	int	i = 0;

	while ((line[*pos] == ' ' || line[*pos] == '\t') && line[*pos] != '\0')
		*pos += 1;
	node->tk_val = I;
	if (is_mnemonic(line + *pos) == 0)
		return (NULL);
	node->mnemo = my_strndup(line + *pos, is_mnemonic(line + *pos));
	*pos += is_mnemonic(line + *pos) + 1;
	node->arg_no = (*pos < my_strlen(line)) ? count_arg(line + *pos) : 0;
	node->arg = malloc(sizeof(char *) * node->arg_no + 8);
	node->tk_name = malloc(sizeof(enum token_e) * node->arg_no);
	for (i = 0; i < node->arg_no; i++) {
		node->arg[i] = my_strndup(line + *pos, is_arg(line + *pos));
		node->tk_name[i] = get_arg_type(line + *pos);
		*pos += is_arg(line + *pos) + 2;
	}
	node->arg[i] = NULL;
	set_mem(node);
	return (node);
}

static struct token *process_line(char *line, int line_no, char *fname,
		int *pos)
{
	struct token	*node = malloc(sizeof(struct token));

	if (node == NULL)
		malloc_error();
	if (is_line_comment(line)) {
		free(node);
		return (NULL);
	}
	node->line = line_no;
	if (is_label(line + *pos)) {
		node = proccess_label(line, pos, node);
	} else {
		if (proccess_mnemonique(line , node, pos) == NULL)
			error_invalid_instruct(fname, line_no);
	}
	return (node);
}

struct d_queue *lex_file(char *fname)
{
	int		fd = open(fname, O_RDONLY);
	int		line_no = 0;
	struct token	*node = NULL;
	struct d_queue	*tmp = NULL;
	char		*line = NULL;

	if (fd < 0)
		return (file_error(fname));
	line = get_next_line(fd);
	while (line) {
		for (int pos = 0; pos < my_strlen(line);) {
			node = process_line(line, ++line_no, fname, &pos);
			tmp = (node) ? add_d_queue(tmp, (void *)node) : tmp;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (tmp);
}
