/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:18:07 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/16 15:22:45 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_tab_size(char *str, char c)
{
	int	i;
	int	nb_mot;

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
