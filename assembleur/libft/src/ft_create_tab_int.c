/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:37:48 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/22 14:09:35 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		**create_tab_int(int x, int y)
{
	int		i;
	int		**tab;

	i = 0;
	if ((tab = (int **)malloc(sizeof(int *) * x + 1)) == NULL)
		return (NULL);
	while (i < x)
	{
		if ((tab[i] = (int *)malloc(sizeof(int) * y + 1)) == NULL)
			return (NULL);
		ft_bzero_int(tab[i], y);
		i++;
	}
	tab[x] = NULL;
	return (tab);
}
