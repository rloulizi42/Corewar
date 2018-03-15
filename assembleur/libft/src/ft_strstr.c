/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:24:30 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/14 18:44:12 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*bi;
	char	*li;

	li = (char *)little;
	bi = (char *)big;
	i = 0;
	if (ft_strlen(li) == 0)
		return (bi);
	while (bi[i])
	{
		j = 0;
		while (bi[i + j] == li[j])
		{
			j++;
			if (!li[j])
				return (bi + i);
		}
		i++;
	}
	return (NULL);
}
