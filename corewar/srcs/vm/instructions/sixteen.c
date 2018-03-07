/*
** EPITECH PROJECT, 2017
** sixteen.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void aff(instructions *instr, champions *champ, circular_memory *vm)
{
	(void) champ;
	(void) vm;
	my_printf("%c\n", instr->arg1);
}

int modif_carry(int carry)
{
	if (carry == 0)
		carry = 1;
	else
		carry = 0;
	return (carry);
}

char *its(int nb)
{
	char	base[10] = "0123456789";
	char	*str = malloc(sizeof(char) * nb);
	int	i = 0;
	int	j = 0;
	int	tmp = 0;

	while (nb != 0) {
		tmp = nb % 10;
		nb = nb / 10;
		while (base[j] != '\0' && itc(tmp) != base[j] - 48)
			++j;
		str[i] = base[j] - 48;
		j = 0;
		++i;
	}
	str[i] = '\0';
	my_revstr(str);
	return (str);
}
