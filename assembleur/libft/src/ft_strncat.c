/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:24:50 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/10 17:12:50 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (n && s2[j] != '\0')
	{
		s1[j + i] = s2[j];
		n--;
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
