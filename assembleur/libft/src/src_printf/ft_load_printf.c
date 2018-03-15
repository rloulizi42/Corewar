/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:06:54 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:21:38 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_load_options(char *format, t_flag **stock)
{
	uintmax_t i;

	i = (*stock)->nb + 1;
	while (format[i] == '#' || format[i] == '+' || format[i] == '-' || \
			format[i] == ' ' || format[i] == '0')
	{
		if (format[i] == '#')
			(*stock)->to_flag |= TO_CONVERT;
		if (format[i] == '+')
			(*stock)->to_flag |= TO_ADD;
		if (format[i] == '-')
			(*stock)->to_flag |= TO_RIGHT;
		if (format[i] == ' ')
			(*stock)->to_flag |= TO_ESPACE;
		if (format[i] == '0')
			(*stock)->to_flag |= TO_ZERO;
		if ((((*stock)->to_flag) & TO_ADD) && \
				((*stock)->to_flag) & TO_ESPACE)
			((*stock)->to_flag) = (*stock)->to_flag & TO_ADD;
		if ((((*stock)->to_flag) & TO_RIGHT) &&\
				((*stock)->to_flag) & TO_ZERO)
			(*stock)->to_flag = (*stock)->to_flag & TO_RIGHT;
		i++;
	}
	(*stock)->nb = i - 1;
}

void	ft_load_field_min(char *format, t_flag **stock)
{
	uintmax_t	i;
	int			tmp;
	int			compare;

	tmp = 0;
	i = (*stock)->nb + 1;
	while (format[i] && ft_isdigit(format[i]))
	{
		(*stock)->zero_field_more = 1;
		compare = format[i] - 48;
		tmp = (10 * tmp) + compare;
		i++;
	}
	if (i > (*stock)->nb)
	{
		if (tmp >= 0 && tmp <= 2147483647)
			(*stock)->field = tmp;
		else if (tmp < 0 || tmp > 2147483647)
			(*stock)->zero_field_more = 0;
	}
	(*stock)->nb = i - 1;
}

void	ft_pres(char *format, t_flag **stock)
{
	int		i;
	int		tmp;
	int		compare;

	tmp = 0;
	compare = 0;
	i = (*stock)->nb + 1;
	if (format[i] && format[i] == '.')
	{
		(*stock)->presi = 1;
		i++;
		while (format[i] && ft_isdigit(format[i]))
		{
			compare = format[i] - 48;
			tmp = (10 * tmp) + compare;
			i++;
		}
		if (tmp >= 0 && tmp <= 2147483647)
			(*stock)->stock_presi = tmp;
		else if (tmp < 0 || tmp > 2147483647)
			(*stock)->presi = 0;
	}
	(*stock)->nb = i - 1;
}

void	ft_option_convert(char *format, t_flag **stock)
{
	uintmax_t	i;

	i = (*stock)->nb + 1;
	if (format[i] && format[i] == 'h' && format[i] && format[i + 1] == 'h')
		(*stock)->convert |= TO_HH;
	else if (format[i] && format[i] == 'h' && (!(((*stock)->convert) & TO_HH)))
		(*stock)->convert |= TO_H;
	else if (format[i] && format[i] == 'l' && format[i] && format[i + 1] == 'l')
		(*stock)->convert |= TO_LL;
	else if (format[i] && format[i] == 'l' && (!(((*stock)->convert) & TO_LL)))
		(*stock)->convert |= TO_L;
	else if (format[i] && format[i] == 'j')
		(*stock)->convert |= TO_J;
	else if (format[i] && format[i] == 'z')
		(*stock)->convert |= TO_Z;
	else
		(*stock)->convert |= NO_CONVERT;
	if ((*stock)->convert != 0 && (!(((*stock)->convert) & NO_CONVERT)))
	{
		if ((*stock)->convert == 1 || (*stock)->convert == 4 || \
				(*stock)->convert == 16 || ((*stock)->convert) == 32)
			(*stock)->nb = (*stock)->nb + 1;
		else
			(*stock)->nb = (*stock)->nb + 2;
	}
}
