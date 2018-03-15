/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:21:49 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/16 15:41:51 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list **list)
{
	t_list *lst;

	lst = (*list);
	if (list)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}
