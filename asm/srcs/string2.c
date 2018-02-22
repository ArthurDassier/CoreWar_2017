/*
** EPITECH PROJECT, 2017
** string2.c
** File description:
** <..>
*/

#include "corewar.h"

static int is_label_char(char ch)
{
	char	*label_char = my_strdup(LABEL_CHARS);

	for (int i = 0; label_char[i]; i++) {
		if (label_char[i] == ch) {
			free(label_char);
			return (1);
		}
	}
	free(label_char);
	return (0);
}

int is_label(char *line)
{
	int	i = 0;

	while (line[i] != '\0') {
		if (line[i] == LABEL_CHAR)
			return (i);
		if (is_label_char(line[i]) == 0)
			return (0);
		++i;
	}
	return (0);
}
