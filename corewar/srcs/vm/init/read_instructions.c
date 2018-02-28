/*
** EPITECH PROJECT, 2017
** read_instructions.c
** File description:
** recup_instructions_of_files
*/

#include "data_base.h"

static void malloc_instruction(instructions *list)
{
	list->mnemonique = malloc(sizeof(char *));
	list->adr = 0;
	list->nb_cycles = 0;
	list->arg1 = 0;
	list->arg2 = 0;
	list->arg3 = 0;
}

static void init_instructions_tab(int (**inst_tab)(instructions *list, int fd))
{
	inst_tab[0] = &live_instruction;
	inst_tab[1] = &ld_instruction;
	inst_tab[2] = &st_instruction;
	inst_tab[3] = &add_instruction;
	inst_tab[4] = &sub_instruction;
	inst_tab[5] = &and_instruction;
	inst_tab[6] = &or_instruction;
	inst_tab[7] = &xor_instruction;
	inst_tab[8] = &zjmp_instruction;
	inst_tab[9] = &ldi_instruction;
	inst_tab[10] = &sti_instruction;
	inst_tab[11] = &fork_instruction;
	inst_tab[12] = &lld_instruction;
	inst_tab[13] = &lldi_instruction;
	inst_tab[14] = &lfork_instruction;
	inst_tab[15] = &aff_instruction;
}

instructions *read_instructions(int fd)
{
	int			rv = 0;
	int			i = 0;
	instructions		*list = malloc(sizeof(instructions));
	instructions		*tmp_list = list;
	int			(*inst_tab[16])(instructions *list, int fd);

	init_instructions_tab(inst_tab);
	while ((rv = read(fd, &i, 1)) != 0) {
		malloc_instruction(list);
		if (inst_tab[i - 1](list, fd) == -1)
			return (NULL);
		printf("==> %s\n", list->mnemonique);
		list->next = malloc(sizeof(instructions));
		list = list->next;
	}
	list->next = NULL;
	return (tmp_list);
}