/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:09:54 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/10 18:52:31 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	put_pos_label_index(t_lst_asm **lst, t_lst_asm *tmp)
{
	int idx;

	idx = 0;
	tmp->nb_final = 0;
	while (*lst)
	{
		if ((*lst)->label_instruc & LABEL_INSTRUC)
			(*lst)->pos_label = tmp->nb_final;
		(*lst)->index = idx;
		idx++;
		tmp->nb_final += (*lst)->nb;
		(*lst)->pos_idx = tmp->nb_final - (*lst)->nb;
		lst = &(*lst)->next;
	}
}

int		find_no_label(t_lst_asm **lst, t_lst_asm *search, int ref)
{
	while (search)
	{
		if (search->label_instruc & LABEL_INSTRUC)
		{
			if ((ft_strxcmp((search)->line, (*lst)->p[ref].label, \
							ft_strclen((search)->line, ':'))) == 0)
				return (1);
		}
		search = search->next;
	}
	return (0);
}

int		find_label(t_lst_asm **lst, t_lst_asm *search)
{
	int	ok;
	int ref;

	ok = 0;
	ref = 0;
	while (*lst)
	{
		ref = 0;
		while ((*lst)->p[ref].if_no_params == 1)
		{
			if ((*lst)->p[ref].label != NULL)
			{
				if (find_no_label(lst, search, ref) == 0)
					ft_exit(1, "label missing\n");
			}
			ref++;
		}
		lst = &(*lst)->next;
	}
	return (1);
}

void	p_label(int ref, t_lst_asm **lst, t_lst_asm *search, t_lst_asm *tmp)
{
	t_lst_asm	*tmp_1;

	tmp_1 = *lst;
	find_label(lst, search);
	lst = &tmp_1;
	search = tmp_1;
	while (search)
	{
		if (search->label_instruc & LABEL_INSTRUC)
		{
			lst = &tmp;
			while (*lst)
			{
				ref = 0;
				while ((*lst)->p[ref].if_no_params == 1)
				{
					get_label_jump(lst, &search, ref);
					ref++;
				}
				lst = &(*lst)->next;
			}
		}
		search = search->next;
	}
}
