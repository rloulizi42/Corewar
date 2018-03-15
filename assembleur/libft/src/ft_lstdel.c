/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:14:00 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/15 19:34:34 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	tmp2 = NULL;
	while (tmp)
	{
		del((tmp)->content, (tmp)->content_size);
		tmp2 = tmp->next;
		free((tmp));
		(tmp) = tmp2;
	}
	(*alst) = NULL;
}
