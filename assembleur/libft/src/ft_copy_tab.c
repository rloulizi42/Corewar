/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:39:12 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/22 14:12:14 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_tab(char **tab)
{
	int		i;
	int		j;
	char	**tab_2;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
			j++;
		i++;
	}
	tab_2 = create_tab(i, j);
	i = 0;
	j = 0;
	while (tab[i])
	{
		ft_strcpy(tab_2[i], tab[i]);
		i++;
	}
	return (tab_2);
}
