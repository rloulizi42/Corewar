/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:42:38 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/10 19:18:46 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		ft_freeall(t_lst_asm **lst)
{
	t_lst_asm	*tmp;
	t_lst_asm	*del;
	int			i;
	int			ref;

	del = *lst;
	tmp = *lst;
	i = 0;
	while (tmp != NULL)
	{
		del = tmp;
		ref = 0;
		while (tmp->p[ref].if_no_params == 1)
		{
			if (tmp->p[ref].label != NULL)
				free(tmp->p[ref].label);
			ref++;
		}
		if (tmp->line != NULL)
			free(tmp->line);
		i++;
		ft_putnbr(i);
		tmp = tmp->prev;
		free(del);
	}
}
