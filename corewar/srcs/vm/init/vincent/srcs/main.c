/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "data_base.h"

int main(int ac, char **av)
{
	instructions	**list = malloc(sizeof(instructions *) * ac);
	int		fd = 0;
	int		i = 0;

	while (ac != 1) {
		printf("\n----- CHAMPION %d -----\n\n", i + 1);
		if ((fd = open(av[i + 1], O_RDONLY)) == -1)
			return (-1);
		if (read_headers(fd) == -1) {
			my_putstr("bad header\n");
			return (84);
		}
		list[i] = malloc(sizeof(instructions));
		if ((list[i] = read_instructions(fd)) == NULL) {
			my_putstr("list failed\n");
			return (84);
		}
		close(fd);
		++i;
		--ac;
	}
	return (0);
}
