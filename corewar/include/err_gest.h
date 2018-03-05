/*
** EPITECH PROJECT, 2017
** err_gest.h
** File description:
** Arthur
*/

#ifndef ERR_GEST_H_
#define ERR_GEST_H_

int ar_er(int ac, char **av);
int check_one_ac(int ac, char **av);

int fct_open(char *av);
int looking_for_flag(char **av, int i);
int hexa_gest(char *av, char *dmp);
int g_flag(char *av);
int check_dump(char *av);
int check_cor(char **av, int i);
int check_fl_n(char *flag, char *av);
int check_fl_a(char *av, char *params);
void put_compil_error(void);
int send_to_flag_handler(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i);
int lf_flag_err(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i);

#endif
