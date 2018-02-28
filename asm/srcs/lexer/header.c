/*
** EPITECH PROJECT, 2017
** header.c
** File description:
** <..>
*/

#include "corewar.h"

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

static void get_header(char *line, header_t *head)
{
	int	i = 0;
	int	inc = 0;

	if (is_name(line)) {
		for (i = is_name(line) + 2, inc = 0; line[i + 1]; i++, inc++)
			head->prog_name[inc]  = line[i];
	}
	if (is_comment(line)) {
		for (i = is_comment(line) + 2, inc = 0; line[i + 1]; i++, inc++)
			head->comment[inc]  = line[i];
	}
}

header_t *create_header(int fd, char *line, char *fname)
{
	header_t	*head = (header_t *)malloc(sizeof(header_t));

	if (head == NULL)
		return (NULL);
	memset(head, 0, sizeof(header_t));
	head->magic = COREWAR_EXEC_MAGIC;
	head->prog_size = 0;
	for (int i = 0; i < PROG_NAME_LENGTH + 1; i++)
		head->prog_name[i] = '\0';
	for (int i = 0; i < COMMENT_LENGTH + 1; i++)
		head->comment[i] = '\0';
	line = get_next_line(fd);
	while (line) {
		if (is_header(line))
			get_header(line, head);
		if (head->prog_name[0] != '\0' && head->comment[0] != '\0') {
			free(line);
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (head);
}
