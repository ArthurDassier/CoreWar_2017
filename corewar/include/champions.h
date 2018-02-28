/*
** EPITECH PROJECT, 2017
** champions.h
** File description:
** champions_h_
*/

#ifndef	CHAMPIONS_H_
#define	CHAMPIONS_H_

#include "my.h"

typedef struct champions
{
	instructions	*list;
	int		*registers;
	char		*pars;
} champions;

int init_champions(champions **champ, int ac, char **av);
void memset_champion_registers(champions *champ);

#endif
