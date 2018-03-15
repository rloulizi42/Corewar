/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:07:16 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/14 18:45:24 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	i = ft_strlen(dst);
	if (size > i)
	{
		ft_strncpy(&dst[i], src, (size - i - 1));
		if (&dst[size - 1])
			dst[size - 1] = '\0';
	}
	if (size <= i)
		return (ft_strlen(src) + size);
	return (i + ft_strlen(src));
}
