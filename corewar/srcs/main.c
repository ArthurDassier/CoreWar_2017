/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Arthur
*/

#include "my.h"

int virtual_machine(char **av)
{
	arguments	argv;
	char		*memory_zone = init_vm(av, &argv);

	if (memory_zone == NULL)
		return (84);
	cycles(memory_zone, &argv);
	free(memory_zone);
	return (0);
}

int main(int ac, char **av)
{
	instructions	**list = malloc(sizeof(instructions) * ac);
	circular_memory	*vm = malloc(sizeof(circular_memory));

	if (ar_er(ac, av) > 0)
		return (84);
	if (init_data_base(list, ac, av) == 84)
		return (84);
	printf("\n----- MEMORY -----\n");
	memory_init(vm, 10);
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'a');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'b');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'c');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'd');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'e');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'f');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'g');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'h');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'i');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'j');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_put(vm, 'k');
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	memory_pop(vm);
	printf("\n== data ==> %s\n", vm->memory);
	printf("== m_end ==> %s\n", vm->memory_end);
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	printf("== count ==> %d\n", vm->count);
	printf("== size  ==> %d\n", vm->size);
	return (0);
}
