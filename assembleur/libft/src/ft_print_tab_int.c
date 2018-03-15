/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:37:48 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/22 14:08:18 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_tab_int(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		dprintf(2, "debut =>");
		j = 0;
		while (tab[i][j])
		{
			dprintf(2, "%3d|", tab[i][j]);
			j++;
		}
		dprintf(2, "pour i => %d\n", i);
		i++;
	}
}
