/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Arthur
*/

#include "my.h"

int virtual_machine(circular_memory *vm, champions **champ, char **av)
{
	arguments	*argv = malloc(sizeof(arguments));

	fill_av(av, argv);
	cycles(vm, champ, argv);
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
	memory_init(vm, champ, MEM_SIZE);
	memory_put(vm, champ[0], '1', 10);
	memory_put(vm, champ[1], '2', 20);
	print_memory(vm->memory);
	virtual_machine(vm, champ, av);
	return (0);
}
