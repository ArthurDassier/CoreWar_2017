/*
** EPITECH PROJECT, 2017
** champions.h
** File description:
** champions_h_
*/

#ifndef	CHAMPIONS_H_
#define	CHAMPIONS_H_

#include "my.h"
#include "data_base.h"

typedef struct champion
{
	instructions	*list;
	int		*registers;
} champions;

int init_champions(champions **champ, int ac, char **av);

#endif
