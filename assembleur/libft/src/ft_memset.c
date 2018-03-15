/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:45:31 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/01/19 13:39:40 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cast_char;

	cast_char = (unsigned char *)b;
	i = -1;
	while (++i < len)
	{
		cast_char[i] = (unsigned char)c;
	}
	return (b);
}
