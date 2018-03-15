/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:59:32 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/01/19 13:40:24 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *tmp;

	if ((tmp = (char*)malloc(sizeof(*tmp) * size)) == 0)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
