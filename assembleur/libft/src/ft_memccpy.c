/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:34:52 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/01/19 13:39:21 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	size_t			verif;
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	stock;

	verif = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	stock = (unsigned char)c;
	i = 0;
	while (n)
	{
		dest[i] = source[i];
		if (source[i] == stock)
		{
			verif++;
			return (dest + i + 1);
		}
		i++;
		n--;
	}
	return (NULL);
}
