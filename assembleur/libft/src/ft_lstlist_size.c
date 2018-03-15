/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlist_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:13:43 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/16 15:42:05 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

int		ft_lstlist_size(t_list *list)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
