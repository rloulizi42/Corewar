/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_label_jump.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:17:28 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/10 12:18:45 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_nb_pos_label(t_lst_asm **lst, int nb, int ref)
{
	int		o;
	int		y;
	char	*convert;

	convert = ft_itoa_base(nb, 16);
	o = ft_strlen(convert);
	o--;
	y = 3;
	while (o >= 0)
	{
		(*lst)->p[ref].stock[y] = convert[o];
		y--;
		o--;
	}
	while (y >= 0)
	{
		(*lst)->p[ref].stock[y] = '0';
		y--;
	}
	free(convert);
}

void	get_label_jump(t_lst_asm **lst, t_lst_asm **search, int ref)
{
	int nb;

	nb = 0;
	if ((*lst)->p[ref].label != NULL)
	{
		if ((ft_strxcmp((*search)->line, (*lst)->p[ref].label, \
						ft_strclen((*search)->line, ':'))) == 0)
		{
			if ((*lst)->index < (*search)->index)
				nb = (*search)->pos_label - (*lst)->pos_idx;
			else if ((*search)->index == (*lst)->index)
				nb = 0;
			else if ((*lst)->index > (*search)->index)
				nb = 0xFFFF + 1 - ((*lst)->pos_idx - (*search)->pos_label);
			get_nb_pos_label(lst, nb, ref);
		}
	}
}
