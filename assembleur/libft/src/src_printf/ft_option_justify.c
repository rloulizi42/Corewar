/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_justify.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:18:39 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 02:00:14 by kkhalfao         ###   ########.fr       */
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

void	ft_save_norme(t_flag **stock, int to_print, char *tmp, intmax_t x)
{
	ft_print_zero(((*stock)->stock_presi - to_print), stock);
	ft_putstr(tmp);
	if (x < 0)
		ft_print_space(((*stock)->field - (*stock)->stock_presi - 1), stock);
	else if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
		ft_print_space(((*stock)->field - (*stock)->stock_presi - 1), stock);
	else
		ft_print_space(((*stock)->field - (*stock)->stock_presi), stock);
}

void	ft_pri_jus_fi_prs(t_flag **stock, int to_print, char *tmp, intmax_t x)
{
	if (((*stock)->field > 0) && (*stock)->presi == 0)
	{
		ft_putstr(tmp);
		ft_order_with_presi(stock, to_print, tmp, x);
	}
	if (((*stock)->field > 0) && (*stock)->presi > 0)
	{
		if ((*stock)->stock_presi - to_print > 0)
			ft_save_norme(stock, to_print, tmp, x);
		else
		{
			ft_putstr(tmp);
			ft_order_with_presi(stock, to_print, tmp, x);
		}
	}
}

void	ft_p_jus_ony_prs(t_flag **stock, int to_print, char *tmp, intmax_t x)
{
	if (((*stock)->field == 0) && (*stock)->stock_presi == 0)
	{
		ft_putstr(tmp);
		ft_order_with_presi(stock, to_print, tmp, x);
	}
	if (((*stock)->field == 0) && (*stock)->stock_presi > 0)
	{
		if ((*stock)->stock_presi - to_print > 0)
		{
			ft_order_with_presi(stock, to_print, tmp, x);
			ft_putstr(tmp);
		}
		else
		{
			ft_putstr(tmp);
			ft_order_with_presi(stock, to_print, tmp, x);
		}
	}
}

void	ft_order_all_flag(t_flag **stock, int to_print, char *tmp, intmax_t x)
{
	if ((*stock)->to_flag & TO_RIGHT)
	{
		ft_print_flag_add_minus_2(stock, x);
		ft_pri_jus_fi_prs(stock, to_print, tmp, x);
		ft_p_jus_ony_prs(stock, to_print, tmp, x);
	}
	else
	{
		ft_order_with_presi(stock, to_print, tmp, x);
		ft_putstr(tmp);
	}
}
