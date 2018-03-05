/*
** EPITECH PROJECT, 2017
** put_instru_in_memory.c
** File description:
** put_instru_in_memory_c_
*/

#include "my.h"

void int_to_str(char *tmp, int nb, int *i)
{
	tmp[*i++] = nb / 1600 + 48;
	tmp[*i++] = nb / 160 % 16 + 48;
	tmp[*i++] = nb / 16 % 16 + 48;
	tmp[*i++] = nb % 16 + 48;
}

void instruction_str(char *tmp, intstrucions *list)
{
	int	i = 0;

	if (my_strlen(list->mnemonique) == 2) {
		tmp[i++] = list->mnemonique[0];
		tmp[i++] = list->mnemonique[1];
	} else {
		tmp[i++] = '0';
		tmp[i++] = list->mnemonique[0];
	}
	int_to_str(tmp, list->arg1, &i);
	int_to_str(tmp, list->arg2, &i);
	int_to_str(tmp, list->arg3, &i);
	tmp[i] = '\0';
}

void put_instru_in_memory(champions *champ, circular_memory *vm)
{
	char	tmp[16];

	while (champ->list != NULL) {
		instruction_str(tmp, champ);
		while (tmp[i] != '\0')
			memory_put(vm, champ, tmp[i++], 1);
		champ->list = champ->list->next;
	}
}
