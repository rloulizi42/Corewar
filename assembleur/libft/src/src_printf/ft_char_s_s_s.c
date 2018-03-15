/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_s_s_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 23:16:11 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:58:47 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <wchar.h>

void		ft_print_percent(t_flag **stock)
{
	ft_putchar('%');
	(*stock)->nb = (*stock)->nb + 1;
	(*stock)->ret = (*stock)->ret + 1;
}

int			ft_count_pres(t_flag **stock, char *str, int print_presi)
{
	while (str[print_presi] && (print_presi < (*stock)->stock_presi))
		print_presi++;
	return (print_presi);
}

void		ft_str_null(t_flag **stock)
{
	(*stock)->nb = (*stock)->nb + 1;
	(*stock)->ret = (*stock)->ret + 6;
	ft_putstr("(null)");
}

void		ft_char_s_s(t_flag **stock, va_list ap)
{
	int		i;
	int		str_len;
	wint_t	*c;

	i = 0;
	c = (wchar_t *)va_arg(ap, wchar_t *);
	str_len = 0;
	if (c)
	{
		str_len = ft_strwlen(c);
		if (str_len <= (*stock)->field)
			i = (*stock)->field - str_len;
		if (i <= 1)
			i = 0;
		if (!(((*stock)->to_flag) & TO_RIGHT))
			ft_print_space(i, stock);
		if (ft_putwstr(c, stock) == -1)
			(*stock)->error++;
		if (((*stock)->to_flag) & TO_RIGHT)
			ft_print_space(i, stock);
		(*stock)->nb = (*stock)->nb + 1;
	}
	else
		ft_str_null(stock);
}
