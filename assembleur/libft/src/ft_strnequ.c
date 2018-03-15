/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:11:34 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/16 14:39:45 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*ss1;
	char	*ss2;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	if (!s1 || !s2)
		return (0);
	while ((ss1[i] == ss2[i]) && ss1[i] && ss2[i] && n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (1);
	if (!(*(ss1 + i)) && !(*(ss2 + i)))
		return (1);
	else
		return (0);
}
