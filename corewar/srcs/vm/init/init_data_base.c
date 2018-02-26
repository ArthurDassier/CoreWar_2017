/*
** EPITECH PROJECT, 2017
** init_data_base.c
** File description:
** init_data_base_c
*/

#include "data_base.h"

int init_data_base(instructions **list, int ac, char **av)
{
	int		fd = 0;
	int		i = 0;

	while (ac != 1) {
		printf("\n----- CHAMPION %d -----\n\n", i + 1);
		if ((fd = open(av[i + 1], O_RDONLY)) == -1) {
			my_putstr("open failed\n");
			return (84);
		}
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
	list[i] = NULL;
	return (0);
}
