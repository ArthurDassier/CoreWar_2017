/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** Arthur
*/

#ifndef INSTR_H_
#define INSTR_H_

void live(instructions *instr, champions *champ, circular_memory *vm);
void ld(instructions *instr, champions *champ, circular_memory *vm);
void st(instructions *instr, champions *champ, circular_memory *vm);
void add(instructions *instr, champions *champ, circular_memory *vm);
void sub(instructions *instr, champions *champ, circular_memory *vm);
void and_inst(instructions *instr, champions *champ, circular_memory *vm);
void or_inst(instructions *instr, champions *champ, circular_memory *vm);
void xor_inst(instructions *instr, champions *champ, circular_memory *vm);
void zjmp(instructions *instr, champions *champ, circular_memory *vm);
void ldi(instructions *instr, champions *champ, circular_memory *vm);
void sti(instructions *instr, champions *champ, circular_memory *vm);
void fork_inst(instructions *instr, champions *champ, circular_memory *vm);
void lld(instructions *instr, champions *champ, circular_memory *vm);
void lldi(instructions *instr, champions *champ, circular_memory *vm);
void lfork(instructions *instr, champions *champ, circular_memory *vm);
void aff(instructions *instr, champions *champ, circular_memory *vm);
int modif_carry(int carry);

#endif
