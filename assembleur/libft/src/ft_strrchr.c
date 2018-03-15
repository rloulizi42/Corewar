/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:00:18 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/14 19:18:21 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	tmp;
	int		i;

	i = 0;
	tmp = (char)c;
	str = (char *)s;
	i = ft_strlen(str);
	if (str[i] == tmp)
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == tmp)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
