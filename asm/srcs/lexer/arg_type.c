/*
** EPITECH PROJECT, 2017
** string3.c
** File description:
** <..>
*/

#include "corewar.h"

enum token_e get_arg_type(char *line)
{
	int	i = 0;

	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (!line || my_strlen(line) < 2)
		return (-1);
	if (line[i] == LABEL_CHAR)
		return (LAB);
	if (line[i] == DIRECT_CHAR && line[i + 1] == LABEL_CHAR)
		return (LAB);
	if (line[i] == DIRECT_CHAR)
		return (DRT);
	if (line[i] == 'r' && my_atoi(line + i + 1) <= 16
			&& my_atoi(line + i + 1) >= 1)
		return (REG);
	return (IND);
}