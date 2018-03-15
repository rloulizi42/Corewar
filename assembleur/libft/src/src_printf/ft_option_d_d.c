/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_d_D.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:59:36 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 02:07:06 by kkhalfao         ###   ########.fr       */
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

void	ft_option_d_d(t_flag **stock, va_list ap)
{
	uintmax_t		x;
	int				to_print;
	char			*tmp;

	tmp = NULL;
	x = ft_search_convert_d_d_d_d(stock, ap);
	to_print = ft_len_number(x, 10);
	if (x == 0)
		tmp = ft_if_nb_is_zero(to_print, stock, 10, x);
	else
		tmp = ft_utoa_base(x, 10);
	if ((*stock)->value == 'u' || (*stock)->value == 'U')
		(*stock)->to_flag = (*stock)->to_flag & ~(1 << 3);
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

void	ft_option_d(t_flag **stock, va_list ap)
{
	intmax_t	x;
	int			to_print;
	char		*tmp;

	tmp = NULL;
	x = ft_search_convert_d(stock, ap);
	to_print = ft_len_number(x, 10);
	if (x == 0)
		tmp = ft_if_nb_is_zero(to_print, stock, 10, x);
	else
		tmp = ft_itoa_base(x, 10);
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
