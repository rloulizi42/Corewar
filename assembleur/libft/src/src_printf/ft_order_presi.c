/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_presi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 19:58:17 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:25:35 by kkhalfao         ###   ########.fr       */
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

void	ft_print_sous_if_presi_neg(int sous, intmax_t x, t_flag **stock)
{
	if (x > 0)
	{
		if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
			ft_print_space(((sous - 1)), stock);
		else
			ft_print_space(sous, stock);
	}
	else
		ft_print_space((sous - 1), stock);
}

void	ft_order_print_space(t_flag **stock, int to_print, intmax_t x, int sous)
{
	if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
	{
		if (ft_len_number(x, 10) <= (*stock)->field)
		{
			if (((*stock)->to_flag & TO_ESPACE) ||\
					(*stock)->to_flag & TO_ADD)
				ft_print_space(((*stock)->field - to_print), stock);
			else
				ft_print_space((sous - to_print), stock);
		}
	}
	else
	{
		if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
			ft_print_space(((*stock)->field \
					- (*stock)->stock_presi - to_print), stock);
		else if (((*stock)->stock_presi - to_print) <= 0 && (x > 0))
			ft_print_space(((*stock)->field - to_print), stock);
		else
			ft_print_space(((*stock)->field - to_print - 1), stock);
	}
}

void	ft_order_field_m_p(t_flag **stock, int to_print, intmax_t x, int sous)
{
	if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
		to_print = to_print + 1;
	if ((*stock)->field > 0 && (((*stock)->stock_presi - to_print) >= 0))
		ft_print_sous_if_presi_neg(sous, x, stock);
	else
		ft_order_print_space(stock, to_print, x, sous);
	if ((ft_print_flag_add_minus(stock, x)) == 0)
		ft_print_if_neg(x, stock);
	if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
		to_print = to_print - 1;
	if ((*stock)->stock_presi > 0)
		ft_print_zero((((*stock)->stock_presi) - to_print), stock);
}

void	ft_order_with_presi(t_flag **stock, int to_print, char *tmp, intmax_t x)
{
	int		sous;
	int		print_pres;
	char	*tmp_2;

	print_pres = (*stock)->stock_presi - to_print;
	sous = (*stock)->stock_presi - (*stock)->field;
	if (sous >= 0)
	{
		if ((ft_enlev_sig(stock) == 1))
			ft_print_zero(print_pres, stock);
		else
		{
			ft_print_flag_add_minus(stock, x);
			ft_print_zero(print_pres, stock);
		}
	}
	if (sous < 0)
	{
		if ((ft_enlev_sig(stock) == 1) && x < 0)
			to_print = to_print - 1;
		sous = -sous;
		ft_order_field_m_p(stock, to_print, x, sous);
	}
	tmp_2 = tmp;
}
