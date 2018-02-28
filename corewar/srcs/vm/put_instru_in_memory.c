/*
** EPITECH PROJECT, 2017
** put_instru_in_memory.c
** File description:
** put_instr_in_memory
*/

#include "my.h"

void put_instru_in_memory(circular_memory *vm, champions *champ)
{
	char	*tmp = malloc(sizeof(char) * 16);
	int	i = 0;

	while (champ->list->next != NULL) {
		instruction_str(tmp, champ->list);
		memory_put(vm, champ, tmp[i++], 0);
		while (tmp[i] != '\0')
			memory_put(vm, champ, tmp[i++], 1);
		i = 0;
		champ->list = champ->list->next;
	}
}

void instruction_str(char *tmp, instructions *list)
{
	tmp[0] = list->mnemonique[0];
	tmp[1] = list->adr / 16 + 48;
	tmp[2] = list->adr % 16 + 48;
	tmp[3] = list->arg1 / 1600 + 48;
	tmp[4] = list->arg1 / 160 % 10 + 48;
	tmp[5] = list->arg1 / 16 % 100 + 48;
	tmp[6] = list->arg1 % 1600 + 48;
	tmp[7] = list->arg2 / 1600 + 48;
	tmp[8] = list->arg2 / 160 % 10 + 48;
	tmp[9] = list->arg2 / 16 % 100 + 48;
	tmp[10] = list->arg2 % 1600 + 48;
	tmp[11] = list->arg3 / 1600 + 48;
	tmp[12] = list->arg3 / 160 % 10 + 48;
	tmp[13] = list->arg3 / 16 % 100 + 48;
	tmp[14] = list->arg3 % 1600 + 48;
	tmp[15] = '\0';
}
