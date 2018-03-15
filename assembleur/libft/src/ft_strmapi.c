/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 19:22:47 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/11 19:32:59 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*tmp;
	unsigned int	i;

	str = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	if ((tmp = (char*)(malloc(sizeof(char) * (ft_strlen(s) + 1)))) == 0)
		return (NULL);
	while (str[i])
	{
		tmp[i] = f(i, str[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
