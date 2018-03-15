/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fisrt_fonctin_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:21:17 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:59:13 by kkhalfao         ###   ########.fr       */
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

char	*ft_flag_zero(t_flag **stock, int to_print, char *tmp, intmax_t x)
{
	int		i;
	int		soustr;
	char	*tmp_2;
	int		y;

	tmp_2 = NULL;
	i = -1;
	x = 0;
	y = -1;
	soustr = (*stock)->field - to_print;
	if (soustr > 0)
	{
		if ((tmp_2 = (char *)malloc(sizeof(char) * \
						(soustr + to_print + 1))) == 0)
			return (NULL);
		ft_bzero(tmp_2, (soustr + to_print + 1));
		while (++i < soustr)
			tmp_2[i] = '0';
		while (++y < to_print)
			tmp_2[i + y] = tmp[y];
		return (tmp_2);
	}
	return (tmp);
}

char	*ft_flag_to_zero(t_flag **stock, int to_print, char *tmp, intmax_t x)
{
	if ((x < 0) && ((*stock)->to_flag & TO_ZERO) && (((*stock)->presi == 0) && \
				((*stock)->stock_presi == 0)))
		to_print = to_print + 1;
	if (((((*stock)->to_flag & TO_ADD) || \
		(*stock)->to_flag & TO_ESPACE)) && (*stock)->to_flag & TO_ZERO)
	{
		if (x > 0)
			(*stock)->field = (*stock)->field - 1;
	}
	if (((*stock)->field - to_print) > 0)
	{
		if ((*stock)->stock_presi > 0)
		{
			if (((*stock)->stock_presi > to_print) \
					&& ((*stock)->field < to_print))
				tmp = ft_flag_zero(stock, to_print, tmp, x);
		}
		else if (((*stock)->presi == 0) && ((*stock)->stock_presi == 0))
		{
			if (ft_enlev_sig(stock) == 1 && x < 0)
				to_print = to_print - 1;
			tmp = ft_flag_zero(stock, to_print, tmp, x);
		}
	}
	return (tmp);
}

int		ft_flag_to_print(t_flag **stock, int to_print, intmax_t x)
{
	int x_2;

	x_2 = x;
	if (((*stock)->field - to_print) > 0)
	{
		if ((*stock)->stock_presi > 0)
		{
			if (((*stock)->stock_presi > to_print) \
					&& ((*stock)->field < to_print))
				to_print = to_print + (*stock)->field - to_print;
		}
		else if (((*stock)->presi == 0) && ((*stock)->stock_presi == 0))
			to_print = to_print + (*stock)->field - to_print;
	}
	return (to_print);
}
