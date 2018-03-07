/*
** EPITECH PROJECT, 2017
** skip.c
** File description:
** <..>
*/

#include "corewar.h"

int skip_tabs(char *line)
{
	int	i = 0;

	while (line[i] != '"' && line[i] != '\0')
		i++;
	return (i);
}

int next_quote(char *line, int inc)
{
	int	i = 0;

	while (line[i] != '"' && line[i] != '\0')
		i++;
	return (i + inc);
}
