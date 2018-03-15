/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:31:18 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 02:08:42 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <wchar.h>
#include "../includes/libft.h"

unsigned long long	ft_len_u_number_p(unsigned long long a, int base)
{
	uintmax_t tmp;

	tmp = 0;
	while (a != 0)
	{
		tmp++;
		a = a / base;
	}
	return (tmp);
}

char				*ft_utoa_base_p(unsigned long long nb, int base)
{
	int		i;
	int		nb_len;
	char	tab_value[17];
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (base < 2 || base > 16)
		return (0);
	nb_len = ft_len_u_number_p(nb, base);
	if ((tmp = (char *)malloc(sizeof(char) * (nb_len + 1))) == 0)
		return (NULL);
	tmp[nb_len] = '\0';
	ft_bzero(tmp, nb_len + 1);
	ft_strcpy(tab_value, "0123456789abcdef");
	while (nb != 0)
	{
		tmp[nb_len - 1] = tab_value[nb % base];
		nb = nb / base;
		nb_len--;
	}
	return (tmp);
}

void				ft_option_p(t_flag **stock, va_list ap)
{
	intmax_t	x;
	int			to_print;
	char		*tmp;

	tmp = NULL;
	x = (unsigned long long)va_arg(ap, unsigned long long);
	to_print = ft_len_u_number_p(x, 16);
	if (x == 0)
		tmp = ft_if_nb_is_zero(to_print, stock, 16, x);
	else
		tmp = ft_utoa_base_p(x, 16);
	tmp = ft_strjoin("0x", tmp);
	to_print = ft_strlen(tmp);
	if ((*stock)->to_flag & TO_ZERO)
	{
		tmp = ft_flag_to_zero(stock, to_print, tmp, x);
		to_print = ft_flag_to_print(stock, to_print, x);
	}
	ft_order_all_flag(stock, to_print, tmp, x);
	(*stock)->ret = (*stock)->ret + ft_strlen(tmp);
	(*stock)->nb = (*stock)->nb + 1;
	free(tmp);
}
