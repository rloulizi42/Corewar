/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_supprimer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:25:41 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 15:57:27 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_diez(char *line, int i)
{
	int end;

	end = ft_strlen(line);
	while (i < end && is_space_tab(line[i]))
		i++;
}

int			check_if_zero(char *line, int *i, int *x, char **tmp)
{
	if (line[*i + *x] == '#')
		return (put_b_zero(tmp, line, i, x));
	return (-1);
}

int			continue_check_label(char *line, int *i, int *x, char **tmp)
{
	if (line[*x + *i] == '#')
		return (put_b_zero(tmp, line, i, x));
	else if ((line[*x + *i] && (!(if_is_label_chars(line[*i + *x]) == 1))) \
			|| (line[*i] == SEPARATOR_CHAR || line[*i] == '/'\
				|| line[*i] == '-' || line[*i] == '+'))
		ft_exit(1, "Label not found\n");
	(*tmp)[*x] = line[*i + *x];
	(*x)++;
	return (2);
}

void		continue_init_struct(t_lst_asm **lst)
{
	(*lst)->ocp = 0;
	(*lst)->no_ocp = 0;
	(*lst)->pos_label = 0;
	(*lst)->pos_idx = 0;
	(*lst)->index = 0;
	(*lst)->ocp = 0;
	(*lst)->fd = 0;
	(*lst)->i = 0;
}

void		init_struct_params(int nb, t_lst_asm **lst)
{
	int i;

	i = 0;
	continue_init_struct(lst);
	while (i < 3)
	{
		ft_bzero((*lst)->p[i].stock, 5);
		(*lst)->p[i].if_no_params = 0;
		(*lst)->p[i].ocp_param = 0;
		(*lst)->p[i].label = NULL;
		(*lst)->p[i].nb = 0;
		(*lst)->p[i].reg = 0;
		(*lst)->p[i].chr = 0;
		(*lst)->p[i].nb = 0;
		ft_bzero(((*lst)->p[i].ins), 10);
		ft_bzero(((*lst)->p[i].stock), 9);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		(*lst)->p[i].if_no_params = 1;
		i++;
	}
}
