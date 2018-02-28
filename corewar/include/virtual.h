/*
** EPITECH PROJECT, 2017
** virtual.h
** File description:
** Arthur
*/

#ifndef VIRTUAL_H_
#define VIRTUAL_H_

typedef struct circular_memory
{
	char	*memory;
	char	*memory_end;
	char	*head;
	char	*tail;
	int	count;
	int	size;
} circular_memory;

void fill_arg(arguments *argv, char *flag, char *parameter);
char *init_vm(char **av, arguments *argv);
int cycles(char *memory_zone, instructions **list, arguments *argv);

int memory_init(circular_memory *vm, int size);
void memory_put(circular_memory *vm, char data);
int is_memory_full(circular_memory *vm);
void memory_pop(circular_memory *vm);
void memory_free(circular_memory *vm);

#define	FULL		(1)
#define	NOT_FULL	(0)

#endif
