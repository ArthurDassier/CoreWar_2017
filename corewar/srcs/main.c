/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Arthur
*/

#include "my.h"

int virtual_machine(char **av, instructions **list)
{
	arguments	argv;
	char		*memory_zone = init_vm(av, &argv);

	if (memory_zone == NULL)
		return (84);
	cycles(memory_zone, list, &argv);
	free(memory_zone);
	return (0);
}

static void print_memory(char *memory)
{
	int	i = 0;

	my_putchar('\n');
	my_putstr("memory : ");
	while (i != my_strlen(memory)) {
		my_putchar(memory[i++]);
		my_putchar(' ');
	}
	my_putstr("\n\n");
}

int main(int ac, char **av)
{
	circular_memory	*vm = malloc(sizeof(circular_memory));
	champions	**champ = malloc(sizeof(champions) * ac);

	if (ar_er(ac, av) > 0)
		return (84);
	if (init_champions(champ, ac, av) == 84)
		return (84);
<<<<<<< HEAD
/*	printf("\n----- MEMORY -----\n");
	memory_init(vm, 5);
	memory_put(vm, 'a');
	memory_put(vm, 'b');
	memory_put(vm, 'c');
	memory_put(vm, 'd');
	memory_put(vm, 'e');
	memory_put(vm, 'f');
	memory_pop(vm);
	printf("\n== data ==> %s\n", vm->memory);
	printf("== m_end ==> %s\n", vm->memory_end);
	printf("== head  ==> %s\n", vm->head);
	printf("== tail  ==> %s\n", vm->tail);
	printf("== count ==> %d\n", vm->count);
	printf("== size  ==> %d\n", vm->size);*/
	virtual_machine(av, list);
=======
	printf("\n----- MEMORY -----\n");
	memory_init(vm, MEM_SIZE);
	print_memory(vm->memory);
>>>>>>> VM
	return (0);
}
