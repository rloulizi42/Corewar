/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:15:42 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/15 18:10:41 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;
	char	*xtp;

	xtp = (char *)s;
	i = 0;
	tmp = NULL;
	if (!s)
		return (NULL);
	if ((tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (NULL);
	while (xtp[i])
	{
		*(tmp + i) = f(xtp[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
