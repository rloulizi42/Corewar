/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:48:24 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/12/17 17:55:23 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strschr(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1)
	{
		if (*ss1 && *ss2 && *ss1 == *ss2)
		{
			i = 0;
			while (*ss1 && *ss2 && *ss1 == *ss2)
			{
				ss1++;
				ss2++;
				i++;
			}
			if (i != ft_strlen(s2))
				ss2 = (unsigned char *)s2;
			else
				break ;
		}
		ss1++;
	}
	return (i != ft_strlen(s2)) ? 0 : 1;
}
