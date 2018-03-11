/*
** EPITECH PROJECT, 2017
** header_error.c
** File description:
** <..>
*/

#include "corewar.h"

header_t *catch_header_error(header_t *head, char *fname, int line_no)
{
	if (head->prog_name[0] == '\0')
		return (NULL);
	if (head->comment[0] == '\0')
		my_printf("asm, %s, line %d: Warning: No comment specified.",
				fname, line_no);
	return (head);
}
