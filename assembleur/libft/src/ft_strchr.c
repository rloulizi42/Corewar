/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:04:02 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/01/20 16:11:48 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;
	char	*str;

	str = (char *)s;
	i = 0;
	tmp = (char)c;
	while (str[i] != '\0')
	{
		if (str[i] == tmp)
		{
			return (str + i);
		}
		i++;
	}
	if (str[i] == c)
		return (str + i);
	else
		return (NULL);
}
