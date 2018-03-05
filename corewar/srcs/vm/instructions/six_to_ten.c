/*
** EPITECH PROJECT, 2017
** six_to_ten.c
** File description:
** Arthur
*/

#include "virtual.h"

void and(int *first, int *two, int *register_one)
{
	*register_one = *first & *two;
}

void or(int *first, int *two, int *register_one)
{
	*register_one = *first | *two;
}

void xor(int *first, int *two, int *register_one)
{
	*register_one = *first ^ *two;
}
