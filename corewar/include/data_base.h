/*
** EPITECH PROJECT, 2017
** data_base.h
** File description:
** data_base_of_instructions_and_headers_errors_handling
*/

#include "my.h"

#ifndef	DATA_BASE_H_
#define	DATA_BASE_H_

typedef struct instructions
{
	char			*mnemonique;
	char			adr;
	int			nb_cycles;
	int			arg1;
	int			arg2;
	int			arg3;
	struct	instructions	*next;
} instructions;

union endian
{
	char	byte[4];
	int	val;
};

int init_data_base(instructions **list, int ac, char **av);

void switch_endian_two(union endian *value);
void switch_endian_four(union endian *value);

int read_headers(int fd);
int check_name_comment(char *name, char *comment);
int headers_error_handling(struct header_s *files_h);

instructions *read_instructions(int fd);
int live_instruction(instructions *list, int fd);
int ld_instruction(instructions *list, int fd);
int st_instruction(instructions *list, int fd);
int add_instruction(instructions *list, int fd);
int sub_instruction(instructions *list, int fd);
int and_instruction(instructions *list, int fd);
int or_instruction(instructions *list, int fd);
int xor_instruction(instructions *list, int fd);
int zjmp_instruction(instructions *list, int fd);
int ldi_instruction(instructions *list, int fd);
int sti_instruction(instructions *list, int fd);
int fork_instruction(instructions *list, int fd);
int lld_instruction(instructions *list, int fd);
int lldi_instruction(instructions *list, int fd);
int lfork_instruction(instructions *list, int fd);
int aff_instruction(instructions *list, int fd);

int read_in_struct(instructions *list, int val, int j, int fd);
struct parameters recup_parameters(int types);
int read_value_of_param(int value, int fd);
int read_parameters(instructions *list, int code, int nb_arg, int fd);

#endif
