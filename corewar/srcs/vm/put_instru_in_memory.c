/*
** EPITECH PROJECT, 2017
** put_instru_in_memory.c
** File description:
** put_instru_in_memory_c_
*/

#include "virtual.h"

void int_to_str(char *tmp, int nb, int *i)
{
	tmp[*i] = nb / 1600 + 48;
	*i += 1;
	tmp[*i] = nb / 160 % 16 + 48;
	*i += 1;
	tmp[*i] = nb / 16 % 16 + 48;
	*i += 1;
	tmp[*i] = nb % 16 + 48;
	*i += 1;
}

void instruction_str(char *tmp, instructions *list)
{
	int	i = 0;

	if (my_strlen(list->mnemonique) == 2) {
		tmp[i++] = list->mnemonique[0];
		tmp[i++] = list->mnemonique[1];
	} else {
		tmp[i++] = '0';
		tmp[i++] = list->mnemonique[0];
	}
	int_to_str(tmp, list->arg1, &i);
	int_to_str(tmp, list->arg2, &i);
	int_to_str(tmp, list->arg3, &i);
	tmp[i] = '\0';
}

void put_one_champ_in_memory(champions *champ, circular_memory *vm)
{
	char	*tmp = malloc(sizeof(char) * 16);
	int	i = 0;

	while (champ->list->next != NULL) {
		instruction_str(tmp, champ->list);
		while (tmp[i] != '\0')
			memory_put(vm, champ, tmp[i++], 1);
		i = 0;
		champ->list = champ->list->next;
	}
}

void put_instructions_in_memory(champions **champ, circular_memory *vm)
{
	int	i = 0;

	while (champ[i] != NULL)
		put_one_champ_in_memory(champ[i++], vm);
}
