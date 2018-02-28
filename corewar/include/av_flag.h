/*
** EPITECH PROJECT, 2017
** av_flag.h
** File description:
** Arthur
*/

#ifndef AV_FLAG_H_
#define AV_FLAG_H_

enum active {
	OFF = 0,
	ON = 1
};

enum flag {
	D = 0,
	A = 1,
	N = 2
};

typedef struct arguments {
	int on_dump;
	int on_n;
	int on_a;
	char *flg_dump;
	char *flg_n;
	char *flg_a;
} arguments;

#endif
