/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_flag_for_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:20:02 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:25:07 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdlib.h>

int			ft_check_if_flag(t_flag **stock, intmax_t x)
{
	if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
		return (0);
	else if (x == 0)
		return (0);
	else if (x < 0)
	{
		ft_putchar('-');
		(*stock)->ret = (*stock)->ret + 1;
	}
	return (1);
}

int			ft_enlev_sig(t_flag **stock)
{
	if ((*stock)->value == 'o')
		return (1);
	if ((*stock)->value == 'O')
		return (1);
	if ((*stock)->value == 'x')
		return (1);
	if ((*stock)->value == 'X')
		return (1);
	if ((*stock)->value == 'u')
		return (1);
	if ((*stock)->value == 'U')
		return (1);
	return (0);
}

int			ft_print_add_minus_norme(t_flag **stock, intmax_t x)
{
	if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
	{
		if ((*stock)->to_flag & TO_ADD)
		{
			if (x < 0)
				ft_putchar('-');
			else if (x >= 0)
				ft_putchar('+');
		}
		else if ((*stock)->to_flag & TO_ESPACE)
		{
			if (x < 0)
				ft_putchar('-');
			else
				ft_putchar(' ');
		}
		(*stock)->ret = (*stock)->ret + 1;
		return (1);
	}
	else
		return (0);
}

int			ft_print_flag_add_minus(t_flag **stock, intmax_t x)
{
	if ((!((*stock)->to_flag & TO_RIGHT)) && (ft_enlev_sig(stock) == 0))
	{
		if (ft_check_if_flag(stock, x) == 0)
		{
			if ((ft_print_add_minus_norme(stock, x)) == 1)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

int			ft_print_flag_add_minus_2(t_flag **stock, intmax_t x)
{
	if (ft_enlev_sig(stock) == 0)
	{
		if (ft_check_if_flag(stock, x) == 0)
		{
			if ((ft_print_add_minus_norme(stock, x)) == 1)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}
