/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:16:42 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/02/22 19:48:29 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	char		*str;
	char		*start;
	int			k;

	k = 0;
	i = 0;
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	start = str;
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[k])
	{
		str[i] = (char)s2[k];
		i++;
		k++;
	}
	str[i] = '\0';
	return (start);
}
