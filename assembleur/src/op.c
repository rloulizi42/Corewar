/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:44:12 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/11 17:30:50 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/parsing.h"

/*
**  {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0}
**  {"nom",
**	nombre de paramètre,
**	type des paramètres,
**	l'opcode
**	nombre de cycle,
**	"la description",
**	booléen de l'octet de codage des paramètres,
**	valeur pour directe et indrecte }
**	il sert a savoir si les paramètres de types directes
**	representes des nombres ou des adresse
**	et donc si ils vont prendre 4 ou 2 octets (edited)
**	`0` pour un nombre (4 octets) et `1` pour une adresse (2 octets)
*/

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 3},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 3},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 3},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 2},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 3},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 4},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 3},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 3},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 4},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 3},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 5},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 3},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

int		check_and_fill_arg(char *line, int i)
{
	if (line[i] && line[i] == ' ')
		i++;
	return (i);
}

int		put_b_zero(char **tmp, char *line, int *i, int *x)
{
	if (line[*i + *x] == '#')
	{
		(*tmp)[*x] = '\0';
		(*x)++;
		*i = ft_strlen(line) - *x;
	}
	return (1);
}

void	check_if_more_arg(char *line, int i)
{
	while (line[i])
	{
		if (!(is_space_tab(line[i])))
			ft_exit(1, "Invalid char after args\n");
		i++;
	}
}

void	fill_y(t_lst_asm **lst, int ref, int y)
{
	while (y >= 0)
	{
		(*lst)->p[ref].stock[y] = '0';
		y--;
	}
}
