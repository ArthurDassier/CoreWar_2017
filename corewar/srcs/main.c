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
	instructions	**list = malloc(sizeof(instructions) * ac);
	circular_memory	*vm = malloc(sizeof(circular_memory));

	if (ar_er(ac, av) > 0)
		return (84);
	if (init_data_base(list, ac, av) == 84)
		return (84);
	printf("\n----- MEMORY -----\n");
	memory_init(vm, MEM_SIZE);
	memory_memset(vm, MEM_SIZE);
	memory_put(vm, '1', 1);
	print_memory(vm->memory);
	printf("== register 1 ==> %d\n", find_register(vm, 1));
	return (0);
}
