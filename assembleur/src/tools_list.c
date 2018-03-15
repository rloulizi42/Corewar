/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:06:54 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/11 14:21:45 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	creer le 1er maillion de la liste
*/

t_lst_asm		*create_t_lst(char *line)
{
	int			len;
	t_lst_asm	*tmp;

	tmp = NULL;
	len = ft_strlen(line);
	if ((tmp = (t_lst_asm*)malloc(sizeof(t_lst_asm))) == 0)
		ft_exit(1, "Malloc error (create_t_lst)\n");
	else
	{
		if ((tmp->line = split_line(line)) == NULL)
			ft_exit(1, "Syntax error\n");
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	return (*(&tmp));
}

void			ft_lstaddback_2(t_lst_asm **lst, t_lst_asm *new)
{
	t_lst_asm *stock;

	if (*lst)
	{
		while ((*lst))
		{
			stock = *lst;
			lst = &(*lst)->next;
		}
		new->prev = stock;
		*lst = new;
	}
	else
	{
		new->prev = NULL;
		*lst = new;
	}
}

/*
**	creer le 1er maillion de la liste ou ajoute les maillion en back
*/

void			create_list_asm(char *line, t_lst_asm **list)
{
	t_lst_asm *tmp;

	if (line != NULL && ft_strlen(line) != 0)
	{
		tmp = create_t_lst(line);
		if (!*(&list))
			(*list) = create_t_lst(line);
		else
			ft_lstaddback_2(list, tmp);
	}
}
