/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:37:43 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/14 19:24:17 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	i = 0;
	dst1 = (char *)dst;
	src1 = (char *)src;
	while (len-- > 0)
	{
		if (src < dst)
			dst1[len] = src1[len];
		else
		{
			*dst1 = *src1;
			dst1 = (dst1 + 1);
			src1 = (src1 + 1);
		}
	}
	return (dst);
}
