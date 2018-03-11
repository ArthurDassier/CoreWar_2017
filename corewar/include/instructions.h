/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** Arthur
*/

#ifndef INSTR_H_
#define INSTR_H_

void live_instru(circular_memory *vm, champions *champ, int types);
void ld_instru(circular_memory *vm, champions *champ, int types);
void st_instru(circular_memory *vm, champions *champ, int types);
void add_instru(circular_memory *vm, champions *champ, int types);
void sub_instru(circular_memory *vm, champions *champ, int types);
void and_instru(circular_memory *vm, champions *champ, int types);
void or_instru(circular_memory *vm, champions *champ, int types);
void xor_instru(circular_memory *vm, champions *champ, int types);
void zjmp_instru(circular_memory *vm, champions *champ, int types);
void ldi_instru(circular_memory *vm, champions *champ, int types);
void sti_instru(circular_memory *vm, champions *champ, int types);
void fork_instru(circular_memory *vm, champions *champ, int types);
void lld_instru(circular_memory *vm, champions *champ, int types);
void lldi_instru(circular_memory *vm, champions *champ, int types);
void lfork_instru(circular_memory *vm, champions *champ, int types);
void aff_instru(circular_memory *vm, champions *champ, int types);
int modif_carry(int carry);

#endif
