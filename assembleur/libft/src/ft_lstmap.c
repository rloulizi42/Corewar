/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:54:02 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/15 19:48:45 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if ((new = ft_lstnew(f(lst)->content, f(lst)->content_size)) == NULL)
		return (NULL);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
