/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** Arthur
*/

typedef struct instructions instructions;
typedef struct arg_champ arg_champ;

typedef struct circular_memory
{
	char	*memory;
	char	*memory_head;
	char	*memory_end;
	int	size;
} circular_memory;

struct arg_champ
{
	int		hyp_a;
	int		hyp_n;
	char		*cor;
	arg_champ	*next;
};

struct instructions
{
	char		*mnemonique;
	char		adr;
	int		nb_cycles;
	int		arg1;
	int		arg2;
	int		arg3;
	instructions	*next;
};

typedef struct champions
{
	instructions	*list;
	int		*registers;
	char		*pars;
} champions;

typedef struct arguments
{
	int	cor;
} arguments;

union endian
{
	char	byte[4];
	int	val;
};
