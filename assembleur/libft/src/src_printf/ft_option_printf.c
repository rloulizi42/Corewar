/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:42:22 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:23:31 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_flag_stars_presi(char *format, t_flag **stock)
{
	uintmax_t	i;

	i = (*stock)->nb + 1;
	if (format[i] && format[i] == '.')
		i++;
	if (format[i] && format[i] == '*')
	{
		(*stock)->bonus |= TO_STARS_2;
		while (format[i] && format[i] == '*')
		{
			(*stock)->stars_presi = (*stock)->stars_presi + 1;
			i++;
		}
	}
	if (i > (*stock)->nb)
		(*stock)->nb = i - 1;
	if (((*stock)->bonus & TO_STARS_2))
		return (1);
	else
		return (0);
}

int		ft_flag_stars_field(char *format, t_flag **stock)
{
	uintmax_t	i;

	i = (*stock)->nb + 1;
	if (format[i] && format[i] == '*')
	{
		(*stock)->bonus |= TO_STARS_1;
		while (format[i] && format[i] == '*')
		{
			(*stock)->stars_field = (*stock)->stars_field + 1;
			i++;
		}
	}
	if (i > (*stock)->nb)
		(*stock)->nb = i - 1;
	if ((*stock)->bonus & TO_STARS_1)
		return (1);
	else
		return (0);
}

void	ft_dollars(char *format, t_flag **stock)
{
	uintmax_t	i;
	int			tmp;

	tmp = 0;
	i = (*stock)->nb + 1;
	while (format[i] && format[i] == '0')
		i++;
	while (format[i] && ft_isdigit(format[i]))
	{
		(*stock)->bonus |= TO_DOLLARS;
		tmp = (10 * tmp) + (format[i] - 48);
		i++;
	}
	if (format[i] == '$' && (i > (*stock)->nb) && ((i - 1) != (*stock)->nb))
	{
		if (tmp > 0 && tmp <= 2147483647)
			(*stock)->dollars = tmp;
		else if (tmp < 0 || tmp > 2147483647)
			(*stock)->bonus = ((*stock)->bonus) & TO_DOLLARS;
		(*stock)->nb = i - 1;
	}
	else
		(*stock)->bonus = ((*stock)->bonus) & TO_DOLLARS;
}
