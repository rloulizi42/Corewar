/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:49:26 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/22 14:10:09 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	**create_tab(int x, int y)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	i = 0;
	if ((tab = (char **)malloc(sizeof(char *) * x + 1)) == NULL)
		return (NULL);
	while (i < x)
	{
		if ((tab[i] = (char *)malloc(sizeof(char) * y + 1)) == NULL)
			return (NULL);
		ft_bzero(tab[i], y);
		i++;
	}
	tab[x] = NULL;
	return (tab);
}
