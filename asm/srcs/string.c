/*
** EPITECH PROJECT, 2017
** string.c
** File description:
** basic string processing functions
*/

#include "corewar.h"

int is_line_comment(char *line)
{
	if (line != NULL && (line[0] == '#' || line [0] == '\0'))
		return (1);
	return (0);
}

int is_header(char *line)
{
	(void) line;
	return (0);
}
