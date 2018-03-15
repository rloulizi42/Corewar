/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:03:33 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:20:45 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdlib.h>

int		ft_len_number(intmax_t a, int base)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (a != 0)
	{
		tmp++;
		a = a / base;
	}
	return (tmp);
}

char	*ft_itoa_base(intmax_t nb, int base)
{
	int		i;
	int		nb_len;
	char	tab_value[17];
	char	*tmp;

	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	nb_len = ft_len_number(nb, base);
	if (nb < 0)
		nb = -nb;
	if ((tmp = (char *)malloc(sizeof(char) * (nb_len + 1))) == 0)
		return (NULL);
	ft_bzero(tmp, nb_len + 1);
	ft_strcpy(tab_value, "0123456789abcdef");
	while (nb != 0)
	{
		if ((nb % base) < 0)
			tmp[nb_len - 1] = tab_value[-(nb % base)];
		else
			tmp[nb_len - 1] = tab_value[nb % base];
		nb = nb / base;
		nb_len--;
	}
	return (tmp);
}
