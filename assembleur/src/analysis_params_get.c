/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_params_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:27:20 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 16:09:46 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** (*lst)->p[ref].if_no_params == le parametre ref (1, 2, 3)
**	g_op_tab[(*lst)->tab].param[ref] -> lst->tab la pos dans le tabeau
**	si le binaire des 2 est la c que le param et bon sinon return -1
**	fait ca sur tout les maillion de la liste et verifie chaque argument
*/

int		analysis(t_lst_asm **lst)
{
	int ref;

	ref = 0;
	while (*lst)
	{
		ref = 0;
		while ((*lst)->p[ref].if_no_params == 1)
		{
			if (!((*lst)->p[ref].ocp_param & g_op_tab[(*lst)->tab].param[ref]))
				ft_exit(1, "Wrong params\n");
			ref++;
		}
		lst = &(*lst)->next;
	}
	return (1);
}

void	check_after_before_quote(char *line, int j, int ref)
{
	int		stock;
	char	*cmp;

	j--;
	if (line[j] == '"')
		j--;
	cmp = (ref == CASE_NAME) ? ".name" : ".comment";
	stock = ft_strlen(cmp) - 1;
	while (is_space_tab(line[j]))
		j--;
	while (cmp[stock] && line[j])
	{
		if (cmp[stock] == line[j])
		{
			stock--;
			j--;
			if (stock == 0)
				break ;
		}
		else
			ft_exit(1, ".name or .comment not well formated\n");
	}
}

void	check_if_no_point(char *line, int *j)
{
	while (is_space_tab(line[*j]))
		(*j)++;
	if (line[*j] != '.')
		ft_exit(1, " not begin by a point\n");
}

void	fill_b_space(char **line, int *i, int len_max)
{
	if (*i < len_max)
	{
		(*line)[*i] = '\n';
		(*i)++;
	}
}
