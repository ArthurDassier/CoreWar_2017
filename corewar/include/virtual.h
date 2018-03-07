/*
** EPITECH PROJECT, 2017
** virtual.h
** File description:
** Arthur
*/

#include "struct.h"
#include "instructions.h"
#include "my.h"
#include "op.h"

#ifndef VIRTUAL_H_
#define VIRTUAL_H_

enum active {
	OFF = 0,
	ON = 1
};

enum flag {
	D = 0,
	A = 1,
	N = 2
};

int ar_er(int ac, char **av);
int check_one_ac(int ac, char **av);

int fct_open(char *av);
int looking_for_flag(char **av, int i);
int hexa_gest(char *av, char *dmp);
int g_flag(char *av);
int check_dump(char *av);
int check_cor(char **av, int i);
int check_fl_n(char *flag, char *av);
int check_fl_a(char *av, char *params);
void put_compil_error(void);
int send_to_flag_handler(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i);
int lf_flag_err(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i);
void reset_cor(char *av, int *hyp_a, int *hyp_n);
int double_arg(int dump, int hyp_a, int hyp_n);

arg_champ *put_arg(int ac, char **av);
arg_champ *init_ag_champ(int hyp_a, int hyp_n, char *av);
void insert_begin(arg_champ **first_elem, int hyp_a, int hyp_n, char *av);
void insert_end(arg_champ **first_elem, int hyp_a, int hyp_n, char *av);
void memory_memset(char *memory, int size);
int adr_acc(int adr);
int set_flag(int adr);

int init_champions(champions **champ, arg_champ *av_list);
void memset_champion_registers(champions *champ);

int init_data_base(instructions **list, arg_champ *av_list);

void switch_endian_two(union endian *value);
void switch_endian_four(union endian *value);

int read_headers(int fd);
int check_name_comment(char *name, char *comment);
int headers_error_handling(struct header_s *files_h);

int memory_init(circular_memory *vm, champions **champ, arg_champ *av_list,
		int size);
void memory_put(circular_memory *vm, champions *champ, char data, int adr);
void put_instructions_in_memory(champions **champ, circular_memory *vm);
int hexo_to_dec(int value, int flag);
void int_to_str(char *tmp, int nb, int *i, int size);
void instruction_str(char *tmp, instructions *list);
void put_one_champ_in_memory(champions *champ, circular_memory *vm);

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
int read_value_of_param(int *types, int value, int fd);
int read_parameters(instructions *list, int code, int nb_arg, int fd);
char *its(int nb);

#endif
