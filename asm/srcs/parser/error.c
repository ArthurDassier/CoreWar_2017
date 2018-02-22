/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** error handling
*/
#include "corewar.h"

static bool	is_valid_param(enum token_e tk_name, int index, int i)
{
	printf("type = %d\n", op_tab[index].type[i]);
	if (tk_name == REG && op_tab[index].type[i] != T_REG)
		return (false);
	if (tk_name == DRT && op_tab[index].type[i] != T_REG | T_DIR | T_IND)
		return (false);
	if (tk_name == IND && op_tab[index].type[i] != T_IND)
		return (false);
	return (true);
}

static int	check_param(struct token *token, int index)
{
	if (token->arg_no != op_tab[index].nbr_args) {
		return (FAILURE);
	}
	for (int i = 0; i < token->arg_no; ++i) {
		if (is_valid_param(token->arg_tab[i].tk_name, index, i) == false)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	error_handling(struct token *token, struct d_queue *head)
{
	struct	header_s	*header = head->token;
	int			index = get_cmd(token->mnemo);

	if (index == FAILURE) {
		my_printf(ERROR_MSG, header->prog_name, token->line,
		"Invalid instruction.\n");
		exit(0);
	}
	if (check_param(token, index) == FAILURE) {
		my_printf(ERROR_MSG, header->prog_name, token->line,
		"The argument given to the instruction is invalid.\n");
		exit(0);
	}
	return (SUCCESS);
}