/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** Arthur
*/

#ifndef INSTR_H_
#define INSTR_H_

void live(int player_number);
void ld(instructions *instr, champions *champ);
void st(instructions *instr, champions *champ);
void add(instructions *instr, champions *champ);
void sub(instructions *instr, champions *champ);
void and(instructions *instr, champions *champ);
void or(instructions *instr, champions *champ);
void xor(instructions *instr, champions *champ);
void zjmp(instructions *instr, champions *champ);
void ldi(instructions *instr, champions *champ);
void sti(instructions *instr, champions *champ);
void fork_inst(instructions *instr, champions *champ);
void lld(instructions *instr, champions *champ);
void lldi(instructions *instr, champions *champ);
void lfork(instructions *instr, champions *champ);
void aff(instructions *instr, champions *champ);
int modif_carry(int carry);

#endif
