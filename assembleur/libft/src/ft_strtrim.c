/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:33:06 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/12 16:28:37 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	char			*ss1;
	unsigned int	start;
	unsigned int	end;
	size_t			i;

	i = 0;
	start = 0;
	end = 0;
	ss1 = (char *)s;
	if (!s)
		return (NULL);
	while (ss1[i] && (ss1[i] == ' ' || ss1[i] == '\t' || ss1[i] == '\n'))
		i++;
	if (ss1[i] == '\0')
		return (ft_strnew(0));
	start = i;
	while (ss1[i])
	{
		if (ss1[i] != ' ' && ss1[i] != '\t' && ss1[i] != '\n')
			end = i;
		i++;
	}
	return (ft_strsub(ss1, start, (size_t)(end - start + 1)));
}
