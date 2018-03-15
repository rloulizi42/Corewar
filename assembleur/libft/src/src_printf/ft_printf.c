/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:07:51 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:25:52 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
#include <limits.h>

void	ft_load_struct(char *format, t_flag **stock)
{
	ft_load_options(format, stock);
	ft_load_field_min(format, stock);
	ft_pres(format, stock);
	ft_option_convert(format, stock);
	(*stock)->value = format[(*stock)->nb + 1];
}

int		ft_until_options(char *format, va_list ap)
{
	int		a;
	t_flag	*stock;

	stock = NULL;
	stock = ft_init_flag(stock);
	while (format[stock->nb])
	{
		if (format[stock->nb] == '%')
		{
			ft_load_struct(format, &stock);
			ft_convert(format, &stock, ap);
			if (stock->error > 0)
				return (-1);
		}
		else
		{
			ft_putchar(format[stock->nb]);
			stock->ret = stock->ret + 1;
		}
		stock->nb = stock->nb + 1;
	}
	a = stock->ret;
	free(stock);
	return (a);
}

int		ft_printf(char *format, ...)
{
	int		ret;
	va_list ap;

	ret = 0;
	va_start(ap, format);
	ret = ft_until_options(format, ap);
	va_end(ap);
	return (ret);
}
