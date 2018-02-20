/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** <..>
*/

#include "corewar.h"

void *file_error(char *fname)
{
	my_printf("%s: does not exist\n", fname);
	return (NULL);
}

void malloc_error(void)
{
	write(2, "Error: malloc NULL pointer\n", 27);
	exit(84);
}
