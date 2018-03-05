/*
** EPITECH PROJECT, 2017
** arg_champ.c
** File description:
** Arthur
*/

#include "data_base.h"

arg_champ *init_ag_champ(int hyp_a, int hyp_n, char *av)
{
	arg_champ	*element = malloc(sizeof(arg_champ));

	element->hyp_a = hyp_a;
	element->hyp_n = hyp_n;
	element->cor = av;
	element->next = NULL;
	return (element);
}

void insert_begin(arg_champ **first_elem, int hyp_a, int hyp_n, char *av)
{
	arg_champ	*new_elem = malloc(sizeof(arg_champ));

	if (new_elem == NULL)
		return;
	new_elem->hyp_a = hyp_a;
	new_elem->hyp_n = hyp_n;
	new_elem->cor = av;
	new_elem->next = *first_elem;
	(*first_elem) = new_elem;
}

void insert_end(arg_champ **first_elem, int hyp_a, int hyp_n, char *av)
{
	arg_champ	*new_elem = malloc(sizeof(arg_champ));
	arg_champ	*actual = (*first_elem);

	if (new_elem == NULL)
		return;
	new_elem->hyp_a = hyp_a;
	new_elem->hyp_n = hyp_n;
	new_elem->cor = av;
	new_elem->next = NULL;
	while (actual->next != NULL)
		actual = actual->next;
	actual->next = new_elem;
}
