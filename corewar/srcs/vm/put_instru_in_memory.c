/*
** EPITECH PROJECT, 2017
** put_instru_in_memory.c
** File description:
** put_instru_in_memory_c_
*/

#include "virtual.h"

int hexa_to_dec(int value, int flag)
{
	if (flag == 4)
		return (value / (16 * 16 * 16) % 16);
	else if (flag == 3)
		return (value / (16 * 16) % 16);
	if (flag == 2)
		return (value / 16 % 16);
	else if (flag == 1)
		return (value % 16);
	return (0);
}

void int_to_str(char *tmp, int nb, int *i, int size)
{
	int	calc = 0;

	while (size != 0) {
		calc = hexa_to_dec(nb, size);
		if (calc >= 0 && calc <= 9)
			tmp[*i] = calc + 48;
		else
			tmp[*i] = calc + 55;
		*i += 1;
		--size;
	}
}

void instruction_str(char *tmp, instructions *list)
{
	int	i = 0;

	tmp[i++] = list->mnemonique[0];
	tmp[i++] = list->mnemonique[1];
	if (list->adr != 0) {
		tmp[i++] = list->adr / (16 * 16) % 16 + 48;
		tmp[i++] = list->adr % 16 + 48;
	}
	int_to_str(tmp, list->arg1, &i, (list->types / 100));
	if (list->arg2 != 0)
		int_to_str(tmp, list->arg2, &i, (list->types / 10 % 10));
	if (list->arg3 != 0)
		int_to_str(tmp, list->arg3, &i, (list->types % 10));
	tmp[i] = '\0';
	printf("== instructions str ==> %s\n", tmp);
}

instructions *put_champ_in_mem(champions *champ, circular_memory *vm)
{
	char		*tmp = malloc(sizeof(char) * 20);
	instructions	*tmp_list = champ->list;
	int		i = 0;

	if (tmp == NULL)
		return (NULL);
	printf("\n");
	while (champ->list->next != NULL) {
		instruction_str(tmp, champ->list);
		while (tmp[i] != '\0')
			memory_put_move(vm, champ, tmp[i++], 1);
		i = 0;
		champ->list = champ->list->next;
	}
	champ->tmp = champ->PC;
	return (tmp_list);
}

int put_instructions_in_memory(champions **champ, circular_memory *vm)
{
	int	i = 0;

	while (champ[i] != NULL) {
		if ((champ[i]->list = put_champ_in_mem(champ[i], vm)) == NULL)
			return (84);
		++i;
	}
	return (0);
}
