/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:36:52 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/14 18:46:16 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *src1;
	char *dst1;

	src1 = (char *)src;
	dst1 = (char *)dst;
	len++;
	while (--len && *src1)
	{
		*(dst1++) = *(src1++);
	}
	while (len--)
	{
		*(dst1++) = '\0';
	}
	return (dst);
}
