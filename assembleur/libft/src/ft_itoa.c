/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:10:49 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/16 10:25:35 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static char		*ft_fill(int n, char *str, unsigned int x)
{
	unsigned int	nb;
	unsigned int	if_neg;
	unsigned int	i;
	unsigned int	stock_len;

	i = 0;
	nb = 0;
	if_neg = 0;
	stock_len = x;
	if (n < 0)
	{
		if_neg++;
		nb = -n;
		str[i] = '-';
		i++;
	}
	if (if_neg == 0)
		nb = (unsigned int)n;
	while (i < x)
	{
		str[x - 1] = nb % 10 + '0';
		nb = nb / 10;
		x--;
	}
	return (str);
}

static int		ft_taille_int(int n)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		taille;

	taille = ft_taille_int(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((str = ft_strnew(taille)) == 0)
		return (0);
	return (str = ft_fill(n, str, ft_taille_int(n)));
}
