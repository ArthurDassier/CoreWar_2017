/*
** EPITECH PROJECT, 2018
** parameters.c
** File description:
** functions to add parameters to .cor
*/
#include "corewar.h"

static void	registers(struct token *token, int fd, int i)
{
	char	*str = malloc((sizeof(*str) * 1) + 1);
	int	result = 0;

	str = my_strcat(str, token->arg_tab[i].args + 1);
	result = my_getnbr(str);
	write(fd, &result, 1);
	result = result >> 2;
	write(fd, &result, 1);
}

static void	directs(struct token *token, int fd, int i)
{
	if (strncmp(":", token->arg_tab[i].args + 1, 1) != 0)
		print_bits(token, fd, i);
}

void	print_bits(struct token *token, int fd, int i)
{
	char	*str = malloc((sizeof(*str) * 1) + 1);
	int	result = 0;
	int	save = 0;

	str = my_strcat(str, token->arg_tab[i].args + 1);
	result = my_getnbr(str);
	save = result;
	for (int j = 1; result >> (j - 1) != 0; ++j)
		result = result >> j;
	if (token->arg_tab[i].tk_name == REG) {
		write(fd, &save, 1);
		write(fd, &result, 1);
	}
	if (token->arg_tab[i].tk_name == DRT) {
		write(fd, &result, 1);
		write(fd, &save, 1);
	}
}

void	add_param(struct d_queue *head, int fd)
{
	struct	token	*token = head->token;

	for (int i = 0; i < token->arg_no; ++i) {
		if (token->arg_tab[i].tk_name != LAB) {
			if (token->arg_tab[i].tk_name == REG) {
				registers(token, fd, i);
			} else if (token->arg_tab[i].tk_name == DRT) {
				directs(token, fd, i);
			}
		}
	}
}