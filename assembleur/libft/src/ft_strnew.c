/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:05:06 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/07 14:02:22 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *tmp;

	if ((tmp = (char *)malloc(sizeof(*tmp) * size + 1)) == 0)
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
