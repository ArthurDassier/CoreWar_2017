/*
** EPITECH PROJECT, 2018
** header.c
** File description:
** functions to write header functions
*/
#include "corewar.h"

static void	fill_empty(int fd, int define)
{
	int	fill = 0;

	for (int i = 0; i < define; ++i)
		write(fd, &fill, 4);
}

void	add_magic(struct d_queue *head, int fd)
{
	struct header_s	*header = head->token;
	union endian	result;

	result.val = header->magic;
	swap_endian(&result);
	write(fd, &result, 4);
}

void	add_name(struct d_queue *head, int fd)
{
	struct header_s	*header = head->token;
	int		c;

	for (int i = 0; header->prog_name[i]; ++i) {
		c = (int)header->prog_name[i];
		write(fd, &c, 1);
	}
	fill_empty(fd, PROG_NAME_LENGTH);
}

void	add_comment(struct d_queue *head, int fd)
{
	struct header_s	*header = head->token;
	int		c;

	for (int i = 0; header->comment[i]; ++i) {
		c = (int)header->comment[i];
		write(fd, &c, 1);
	}
	fill_empty(fd, COMMENT_LENGTH);
}