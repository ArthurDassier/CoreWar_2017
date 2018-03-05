/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Arthur
*/

#include "my.h"

int virtual_machine(circular_memory *vm, champions **champ)
{
	arguments	*argv = malloc(sizeof(arguments));

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
	print_memory(vm->memory);
	return (0);
}
