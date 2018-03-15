/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:56:29 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/09 15:44:56 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		write_upcode(char **tmp, int i, t_lst_asm **lst)
{
	int		end;
	int		exe;

	exe = g_op_tab[(*lst)->tab].opcode;
	end = i;
	while ((i - end) >= 0)
	{
		(*tmp)[i] = exe;
		exe >>= 8;
		i--;
	}
	write(((*lst)->fd), (*tmp) + end, 1);
	(*lst)->i = end + 1;
	return (end + 1);
}

int		write_exe_code(char **tmp, int i, int fd)
{
	int		exe;

	exe = COREWAR_EXEC_MAGIC;
	while (i >= 0)
	{
		(*tmp)[i] = exe;
		exe >>= 8;
		i--;
	}
	write(fd, *tmp, 4);
	return (4);
}

int		write_prog_name(char **tmp, int fd, char *name, int len)
{
	int i;
	int x;
	int max;
	int ref;

	x = 0;
	i = (len == 128) ? 4 : 140;
	ref = (len == 128) ? 4 : 140;
	max = (len == 128) ? 128 : 2048;
	while (name[x])
	{
		(*tmp)[i] = name[x];
		x++;
		i++;
	}
	while (x < max)
	{
		(*tmp)[i] = 0;
		x++;
		i++;
	}
	write(fd, ((*tmp) + ref), max);
	return (i);
}

int		write_null(char **tmp, int i, int fd)
{
	int		zero;

	zero = 3 + i;
	while ((zero - i) >= 0)
	{
		(*tmp)[zero] = 0;
		zero--;
	}
	write(fd, ((*tmp) + i), 4);
	return (i + 4);
}

int		write_nb_arg(char **tmp, int i, int fd, t_lst_asm **lst)
{
	int		nb_arg;
	int		ref;
	int		s;

	s = 3;
	ref = i;
	i = i + 3;
	nb_arg = (*lst)->nb_final;
	while (s >= 0)
	{
		(*tmp)[i] = nb_arg;
		nb_arg >>= 8;
		i--;
		s--;
	}
	write(fd, ((*tmp) + ref), 4);
	return (ref + 4);
}
