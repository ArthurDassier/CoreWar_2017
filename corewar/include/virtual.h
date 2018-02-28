/*
** EPITECH PROJECT, 2017
** virtual.h
** File description:
** Arthur
*/

#ifndef VIRTUAL_H_
#define VIRTUAL_H_

void fill_arg(arguments *argv, char *flag, char *parameter);
char *init_vm(char **av, arguments *argv);
int cycles(char *memory_zone, arguments *argv);

#endif
