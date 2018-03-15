/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:33:49 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/12/14 15:05:37 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin_free(char *str, char *buf)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, buf);
	free(tmp);
	return (str);
}
