/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** Arthur
*/

#ifndef INSTR_H_
#define INSTR_H_

void live_instru(instructions *instr, champions *champ, circular_memory *vm);
void ld_instru(instructions *instr, champions *champ, circular_memory *vm);
void st_instru(instructions *instr, champions *champ, circular_memory *vm);
void add_instru(instructions *instr, champions *champ, circular_memory *vm);
void sub_instru(instructions *instr, champions *champ, circular_memory *vm);
void and_instru(instructions *instr, champions *champ, circular_memory *vm);
void or_instru(instructions *instr, champions *champ, circular_memory *vm);
void xor_instru(instructions *instr, champions *champ, circular_memory *vm);
void zjmp_instru(instructions *instr, champions *champ, circular_memory *vm);
void ldi_instru(instructions *instr, champions *champ, circular_memory *vm);
void sti_instru(instructions *instr, champions *champ, circular_memory *vm);
void fork_instru(instructions *instr, champions *champ, circular_memory *vm);
void lld_instru(instructions *instr, champions *champ, circular_memory *vm);
void lldi_instru(instructions *instr, champions *champ, circular_memory *vm);
void lfork_instru(instructions *instr, champions *champ, circular_memory *vm);
void aff_instru(instructions *instr, champions *champ, circular_memory *vm);
int modif_carry(int carry);

#endif
