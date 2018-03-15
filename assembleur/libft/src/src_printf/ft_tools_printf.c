/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:44:11 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:34:41 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_space(intmax_t i, t_flag **stock)
{
	if (i > 0)
		(*stock)->ret = (*stock)->ret + i;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void	ft_print_zero(intmax_t i, t_flag **stock)
{
	if (i > 0)
		(*stock)->ret = (*stock)->ret + i;
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

t_flag	*ft_init_flag(t_flag *stock)
{
	t_flag	*stock_2;

	if ((stock_2 = (t_flag*)malloc(sizeof(t_flag))) == 0)
		return (NULL);
	stock_2->nb = 0;
	stock_2->ret = 0;
	stock_2->to_flag = 0;
	stock_2->convert = 0;
	stock_2->field = 0;
	stock_2->zero_field_more = 0;
	stock_2->presi = 0;
	stock_2->stock_presi = 0;
	stock_2->bonus = 0;
	stock_2->dollars = 0;
	stock_2->stars_field = 0;
	stock_2->stars_presi = 0;
	stock_2->value = 0;
	stock_2->error = 0;
	stock = NULL;
	return (*(&stock_2));
}
