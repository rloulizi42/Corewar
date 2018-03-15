/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_check_indir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:30:35 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/11 20:03:34 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** REGISTRE
*/

void		fill_reg(int stock, t_lst_asm **lst, int ref)
{
	char *tmp;

	tmp = ft_itoa_base(stock, 16);
	if (ft_strlen(tmp) == 2)
	{
		(*lst)->p[ref].stock[0] = tmp[0];
		(*lst)->p[ref].stock[1] = tmp[1];
		(*lst)->p[ref].stock[2] = '\0';
	}
	else
	{
		(*lst)->p[ref].stock[0] = tmp[0];
		(*lst)->p[ref].stock[1] = '\0';
	}
	free(tmp);
}

int			f_reg(int i, char *line, t_lst_asm **lst, int ref)
{
	int		stock;

	stock = 0;
	i++;
	if (line[i] && ft_isdigit(line[i]))
		stock = ft_atoi(line + i);
	else
		ft_exit(1, "Reg format error\n");
	(*lst)->p[ref].reg = stock;
	(*lst)->p[ref].ocp_param |= T_REG;
	get_ocp(lst, ref, REG_CODE);
	(*lst)->nb += 1;
	(*lst)->p[ref].chr = 1;
	if (stock < 1 || stock > REG_NUMBER)
		ft_exit(-1, "Wrong reg number\n");
	if (stock <= REG_NUMBER)
		fill_reg(stock, lst, ref);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	return (i + 1);
}

void		fill_list_value(t_lst_asm **lst, int ref)
{
	char	*tmp;
	int		x;
	int		y;

	tmp = ft_itoa_base((*lst)->p[ref].nb, 16);
	x = ft_strlen(tmp);
	y = 3;
	x = x - 1;
	while (x >= 0 && tmp[x] && y >= 0)
	{
		(*lst)->p[ref].stock[y] = tmp[x];
		y--;
		x--;
	}
	while (y >= 0)
	{
		(*lst)->p[ref].stock[y] = '0';
		y--;
	}
	free(tmp);
	if (((*lst)->tab == LIVE) || ((*lst)->tab == ZJUMP) ||\
			((*lst)->tab == FORK) || ((*lst)->tab == LFORK))
		(*lst)->no_ocp = 1;
}

int			f_nb_indir(int i, char *line, t_lst_asm **lst, int ref)
{
	long long int stock;

	stock = 0;
	if (line[i] && line[i] == '-' && line[i + 1] && ft_isdigit(line[i + 1]))
	{
		stock = ft_atoi_lld(line + i);
		i++;
	}
	else if (line[i] && ft_isdigit(line[i]))
		stock = ft_atoi_lld(line + i);
	else
		ft_exit(1, "Wrong indir arg format\n");
	if (stock < 0)
		(*lst)->p[ref].nb = (stock % 0xFFFF + 0xFFFF) % 0xFFFF + 1;
	else
		(*lst)->p[ref].nb = stock % 0xFFFF;
	(*lst)->p[ref].ocp_param |= T_IND;
	get_ocp(lst, ref, IND_CODE);
	(*lst)->nb += 2;
	(*lst)->p[ref].chr += 2;
	fill_list_value(lst, ref);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	i++;
	return (i);
}
