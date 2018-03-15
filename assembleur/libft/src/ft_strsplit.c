/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:51:24 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/01/19 15:15:43 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int		ft_nbcol(char *str, char c)
{
	int	i;
	int nb_mot;

	i = 0;
	nb_mot = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c && str[i + 1] == c)
			nb_mot++;
		if (!str[i])
			break ;
		i++;
	}
	if (i > 0)
		if (!str[i] && str[i - 1] != c)
			nb_mot++;
	return (nb_mot);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		start;
	int		index;

	i = 0;
	start = 0;
	index = -1;
	if (!s)
		return (NULL);
	if ((tab = malloc(sizeof(char *) * (ft_nbcol((char *)s, c) + 1))) == 0)
		return (0);
	tab[(ft_nbcol((char *)s, c))] = NULL;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[++index] = ft_strsub(s, (unsigned int)start, (size_t)i - start);
	}
	return (tab);
}
