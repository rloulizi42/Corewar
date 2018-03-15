/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:12:28 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:23:56 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <wchar.h>

void		ft_1(int print_presi, t_flag **stock, char *c, int i)
{
	if ((*stock)->stock_presi > 0)
	{
		print_presi = ft_count_pres(stock, c, print_presi);
		ft_print_space((*stock)->field - print_presi, stock);
	}
	else
		ft_print_space(i, stock);
}

int			ft_case_spec_2(char *c, t_flag **stock, int print_presi)
{
	if ((*stock)->stock_presi > 0)
	{
		print_presi = 0;
		while (c[print_presi] && (print_presi < (*stock)->stock_presi))
		{
			ft_putchar(c[print_presi]);
			print_presi++;
		}
	}
	else
		ft_putstr(c);
	return (print_presi);
}

int			ft_case_spec_3(char *c, t_flag **stock, int print_presi, int i)
{
	int strlen;

	strlen = ft_strlen(c);
	if (((*stock)->to_flag) & TO_RIGHT)
	{
		if ((*stock)->stock_presi > 0)
		{
			print_presi = ft_count_pres(stock, c, print_presi);
			ft_print_space((*stock)->field - print_presi, stock);
		}
		else
			ft_print_space(i, stock);
	}
	if ((*stock)->stock_presi > 0)
		(*stock)->ret = (*stock)->ret + print_presi;
	else
		(*stock)->ret = (*stock)->ret + strlen;
	(*stock)->nb = (*stock)->nb + 1;
	return (print_presi);
}

void		ft_case_speci(t_flag **stock, char *c)
{
	int		strlen;
	int		i;
	int		print_presi;

	print_presi = 0;
	i = 0;
	strlen = ft_strlen(c);
	if (strlen <= (*stock)->field)
		i = (*stock)->field - strlen;
	if (i <= 1)
		i = 0;
	if (!(((*stock)->to_flag) & TO_RIGHT))
		ft_1(print_presi, stock, c, i);
	print_presi = ft_case_spec_2(c, stock, print_presi);
	print_presi = ft_case_spec_3(c, stock, print_presi, i);
}

void		ft_char_s(t_flag **stock, va_list ap)
{
	char	*c;
	wchar_t	*x;
	int		print_presi;

	print_presi = 0;
	if ((*stock)->convert & TO_L)
	{
		x = (wchar_t *)va_arg(ap, wchar_t *);
		ft_char_s_long(stock, x);
		return ;
	}
	else
		c = (char *)va_arg(ap, char *);
	if (c != NULL)
		ft_case_speci(stock, c);
	else
		ft_str_null(stock);
}
