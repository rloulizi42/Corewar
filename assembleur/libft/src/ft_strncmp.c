/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:17:54 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/02/24 15:46:10 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 == *ss2 && n && *ss1 && *ss2)
	{
		ss1++;
		ss2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ss1 - *ss2);
}
