/*
** EPITECH PROJECT, 2018
** adressage.c
** File description:
** functions to do the adressage
*/
#include "corewar.h"

static int	adressage(struct token *token)
{
	int	result = 0;

	result = result << 2;
	for (int i = 0; i < token->arg_no; ++i) {
		if (token->arg_tab[i].tk_name == REG) {
			result += 1;
			result = result << 2;
		}
		if (token->arg_tab[i].tk_name == DRT) {
			result += 2;
			result = result << 2;
		}
		if (token->arg_tab[i].tk_name == IND) {
			result += 3;
			result = result << 2;
		}
	}
	return (result);
}

static bool	check_exception(char *str)
{
	if (my_strcmp(str, "zjump") == 0 || my_strcmp(str, "live") == 0 ||
	my_strcmp(str, "lfork") == 0 || my_strcmp(str, "fork") == 0)
		return (true);
	return (false);
}

void	add_adressage(struct token *token, int fd)
{
	int		result;

	if (check_exception(token->mnemo) == true)
		return;
	result = adressage(token);
	write(fd, &result, 1);
}