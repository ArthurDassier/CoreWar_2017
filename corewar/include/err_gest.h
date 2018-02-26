/*
** EPITECH PROJECT, 2017
** err_gest.h
** File description:
** Arthur
*/

#ifndef ERR_GEST_H_
#define ERR_GEST_H_

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

int ar_er(int ac, char **av);
int check_ac_nb(int ac);
int check_one_ac(int ac);

int looking_for_flag(char **av);
int hexa_gest(char *av, char *dmp);
int g_flag(char *av);
int check_dump(char *av);
int check_cor(int ac, char **av, int i);
int check_fl_n(char *flag, char *av);
int check_fl_a(char *av, char *params);

#endif
