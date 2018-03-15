/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:39:12 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/22 14:12:27 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_copy_tab_int(int **tab)
{
	int i;
	int j;
	int **tab_2;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
			j++;
		i++;
	}
	tab_2 = create_tab_int(i, j);
	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			tab_2[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (tab_2);
}
