/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:48:00 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/01/18 16:38:53 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstaddback(t_list **lst, t_list *new)
{
	t_list *tmp;

	tmp = *lst;
	if (new)
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = &(*new);
		(*lst) = &(*tmp);
	}
	else
		ft_lstnew((*lst)->content, (*lst)->content_size);
}
