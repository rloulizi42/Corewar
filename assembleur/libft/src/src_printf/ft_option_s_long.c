/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_s_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:55:54 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:24:21 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <wchar.h>

void		ft_2(int print_presi, t_flag **stock, wchar_t *c, int i)
{
	if ((*stock)->stock_presi > 0)
	{
		print_presi = ft_count_pres_long(stock, c, print_presi);
		ft_print_space((*stock)->field - print_presi, stock);
	}
	else
		ft_print_space(i, stock);
}

int			ft_case_spec_2_2(wchar_t *c, t_flag **stock, int print_presi)
{
	if ((*stock)->stock_presi > 0)
	{
		print_presi = 0;
		while (c[print_presi] && (print_presi < (*stock)->stock_presi))
		{
			ft_putwchar(c[print_presi]);
			print_presi++;
		}
	}
	else
	{
		if (ft_putwstr(c, stock) == -1)
			(*stock)->error++;
	}
	return (print_presi);
}

int			ft_case_spec_2_3(wchar_t *c, t_flag **stock, int print_presi, int i)
{
	if (((*stock)->to_flag) & TO_RIGHT)
	{
		if ((*stock)->stock_presi > 0)
		{
			print_presi = ft_count_pres_long(stock, c, print_presi);
			ft_print_space((*stock)->field - print_presi, stock);
		}
		else
			ft_print_space(i, stock);
	}
	if ((*stock)->stock_presi > 0 || (*stock)->field > 0)
		(*stock)->ret = (*stock)->ret + print_presi;
	else
		(*stock)->ret = (*stock)->ret + print_presi;
	(*stock)->nb = (*stock)->nb + 1;
	return (print_presi);
}

void		ft_case_speci_s_long(t_flag **stock, wchar_t *c)
{
	int i;
	int strlen;
	int print_presi;

	print_presi = 0;
	i = 0;
	strlen = ft_strwlen(c);
	if (strlen > 0 && strlen <= (*stock)->field)
		i = (*stock)->field - strlen;
	if (i <= 1)
		i = 0;
	if (!(((*stock)->to_flag) & TO_RIGHT))
		ft_2(print_presi, stock, c, i);
	print_presi = ft_case_spec_2_2(c, stock, print_presi);
	print_presi = ft_case_spec_2_3(c, stock, print_presi, i);
}

void		ft_char_s_long(t_flag **stock, wchar_t *c)
{
	if (c != NULL)
		ft_case_speci_s_long(stock, c);
	else
	{
		(*stock)->nb = (*stock)->nb + 1;
		(*stock)->ret = (*stock)->ret + 6;
		ft_putstr("(null)");
	}
}
