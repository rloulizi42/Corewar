/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:33:06 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/01/19 15:18:42 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*tmp;
	unsigned int	j;
	unsigned int	i;
	unsigned int	b;

	b = 0;
	i = 0;
	j = 0;
	str = (char *)s;
	if (!s)
		return (0);
	if ((tmp = (char*)malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	while (len)
	{
		tmp[i] = str[start];
		i++;
		len--;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}
