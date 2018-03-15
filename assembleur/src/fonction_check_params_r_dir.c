/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_check_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:12:35 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 17:48:00 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			f_label_indir(int i, char *line, t_lst_asm **lst, int ref)
{
	int		space;
	char	*stock;

	stock = NULL;
	i = i + 1;
	space = i;
	if (line[i])
	{
		while (line[space] && line[space] != ' ' && line[space] != '\t')
			space++;
		if ((stock = ft_strndup(line + i, (space - i))) == NULL)
			ft_exit(1, "Malloc error (f_label_indir)\n");
	}
	else
		ft_exit(1, "Label does not exist\n");
	(*lst)->p[ref].label = &(*stock);
	(*lst)->p[ref].ocp_param |= T_IND;
	get_ocp(lst, ref, IND_CODE);
	(*lst)->nb += 2;
	(*lst)->p[ref].chr = 2;
	if (((*lst)->tab == LIVE) || ((*lst)->tab == ZJUMP) || \
			((*lst)->tab == FORK) || ((*lst)->tab == LFORK))
		(*lst)->no_ocp = 1;
	return (i + space - i);
}

/*
** DIRECTE NB f_nb_dir et f_label_dir
*/

void		fill_nb_dir_arg(t_lst_asm **lst, int ref)
{
	char	*tmp;
	int		x;
	int		y;

	tmp = ft_itoa_base((*lst)->p[ref].nb, 16);
	x = ft_strlen(tmp) - 1;
	y = (g_op_tab[(*lst)->tab].size_dir == 0) ? 7 : 3;
	(*lst)->p[ref].ocp_param |= T_DIR;
	get_ocp(lst, ref, DIR_CODE);
	(*lst)->nb += (g_op_tab[(*lst)->tab].size_dir == 0) ? 4 : 2;
	(*lst)->p[ref].chr = (g_op_tab[(*lst)->tab].size_dir == 0) ? 4 : 2;
	while (x >= 0 && tmp[x] && y >= 0)
	{
		(*lst)->p[ref].stock[y] = tmp[x];
		y--;
		x--;
	}
	fill_y(lst, ref, y);
	free(tmp);
	if (((*lst)->tab == LIVE) || ((*lst)->tab == ZJUMP) || \
			((*lst)->tab == FORK) || ((*lst)->tab == LFORK))
		(*lst)->no_ocp = 1;
}

void		get_nb_dir(t_lst_asm **lst, long long int stock, int ref)
{
	if (stock < 0)
	{
		if (g_op_tab[(*lst)->tab].size_dir == 0)
			(*lst)->p[ref].nb = (stock % 0xFFFFFFFF + 0xFFFFFFFF) \
								% 0xFFFFFFFF + 1;
		else
			(*lst)->p[ref].nb = (stock % 0xFFFF + 0xFFFF) % 0xFFFF + 1;
	}
	else
	{
		if (g_op_tab[(*lst)->tab].size_dir == 0)
			(*lst)->p[ref].nb = stock % 0xFFFFFFFF;
		else
			(*lst)->p[ref].nb = stock % 0xFFFF;
	}
}

int			f_nb_dir(int i, char *line, t_lst_asm **lst, int ref)
{
	long long int stock;

	stock = 0;
	i++;
	if (line[i] && line[i] == '-' && line[i + 1] && ft_isdigit(line[i + 1]))
	{
		stock = ft_atoi_lld(line + i);
		i++;
	}
	else if (line[i] && ft_isdigit(line[i]))
		stock = ft_atoi_lld(line + i);
	else
		ft_exit(1, "Wrong nb for dir arg\n");
	get_nb_dir(lst, stock, ref);
	fill_nb_dir_arg(lst, ref);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	i++;
	return (i);
}

int			f_label_dir(int i, char *line, t_lst_asm **lst, int ref)
{
	int		space;
	char	*stock;

	stock = NULL;
	i = i + 2;
	space = i;
	if (line[i])
	{
		while (line[space] && line[space] != ' ' && line[space] != '\t')
			space++;
		if ((stock = ft_strndup(line + i, (space - i))) == NULL)
			ft_exit(1, "Malloc error (f_label_dir)\n");
	}
	else
		ft_exit(1, "No number in dir arg\n");
	(*lst)->p[ref].label = &(*stock);
	(*lst)->p[ref].ocp_param |= T_DIR;
	get_ocp(lst, ref, DIR_CODE);
	(*lst)->nb += (g_op_tab[(*lst)->tab].size_dir == 0) ? 4 : 2;
	(*lst)->p[ref].chr = (g_op_tab[(*lst)->tab].size_dir == 0) ? 4 : 2;
	if (((*lst)->tab == LIVE) || ((*lst)->tab == ZJUMP) \
			|| ((*lst)->tab == FORK) || ((*lst)->tab == LFORK))
		(*lst)->no_ocp = 1;
	return (i + space - i);
}
