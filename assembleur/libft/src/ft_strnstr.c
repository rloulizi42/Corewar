/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:01:57 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/16 14:19:21 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	i;

	b = 0;
	i = 0;
	while (((char *)big)[b] && i < len && ((char *)big)[b])
	{
		l = 0;
		while (((char *)big)[b] == ((char *)little)[l] && \
				((char *)little)[l] && i < len)
		{
			b++;
			l++;
			i++;
		}
		if (!(((char *)little)[l]))
			return (&((char *)big)[b - l]);
		b -= (l - 1);
		i -= (l - 1);
	}
	return (NULL);
}
