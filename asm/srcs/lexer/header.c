/*
** EPITECH PROJECT, 2017
** header.c
** File description:
** <..>
*/

#include "corewar.h"

static void set_zero(header_t *head)
{
	memset(head, 0, sizeof(header_t));
	head->magic = COREWAR_EXEC_MAGIC;
	head->prog_size = 0;
	for (int i = 0; i < PROG_NAME_LENGTH + 1; i++)
		head->prog_name[i] = '\0';
	for (int i = 0; i < COMMENT_LENGTH + 1; i++)
		head->comment[i] = '\0';
}

static int is_name(char *line)
{
	char	name[6] = ".name\0";
	int	i = 0;
	int	ind = 0;

	while ((line[ind] == ' ' || line[ind] == '\t') && line[ind] != '\0')
		ind++;
	for (i = ind; i < ind + 5; i++) {
		if (line[i] != name[i - ind])
			break;
	}
	if (i == ind + 5)
		return (i);
	return (0);
}

static int is_comment(char *line)
{
	char	name[9] = ".comment\0";
	int	i = 0;
	int	ind = 0;

	while ((line[ind] == ' ' || line[ind] == '\t') && line[ind] != '\0')
		ind++;
	for (i = ind; i < ind + 8; i++) {
		if (line[i] != name[i - ind])
			break;
	}
	if (i == ind + 8)
		return (i);
	return (0);
}

static void get_header(char *line, header_t *head, char *fname, int *line_no)
{
	int	i = 0;
	int	inc = 0;

	if (is_name(line)) {
		if (head->prog_name[0] != '\0')
			error_name(fname, *line_no);
		for (i = next_quote(line, 0) + 1, inc = 0; line[i] != '"'
				&& line[i] ; i++, inc++)
			head->prog_name[inc]  = line[i];
		if (line[i] == '\0' || is_noise(line + i + 1))
			syntax_error(fname, *line_no);
	}
	if (is_comment(line)) {
		if (head->comment[0] != '\0')
			error_comment(fname, *line_no);
		for (i = next_quote(line, 0) + 1, inc = 0; line[i] != '"'
				&& line[i]; i++, inc++)
			head->comment[inc]  = line[i];
		if (line[i] == '\0' || is_noise(line + i + 1))
			syntax_error(fname, *line_no);
	}
}

header_t *create_header(int fd, char *line, char *fname, int *line_no)
{
	header_t	*head = (header_t *)malloc(sizeof(header_t));

	if (head == NULL)
		return (NULL);
	set_zero(head);
	line = get_next_line(fd);
	while (line) {
		*line_no += 1;
		if (is_header(line))
			get_header(line, head, fname, line_no);
		if (head->prog_name[0] != '\0' && head->comment[0] != '\0') {
			free(line);
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (head);
}
