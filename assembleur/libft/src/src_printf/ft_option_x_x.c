/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:23:36 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 02:09:25 by kkhalfao         ###   ########.fr       */
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

void	ft_option_x(t_flag **stock, va_list ap, char *format)
{
	uintmax_t	x;
	int			to_print;
	char		*tmp;

	x = ft_search_convert_d_d_d_d(stock, ap);
	to_print = ft_len_u_number(x, 10);
	if (x == 0)
		tmp = ft_if_nb_is_zero(to_print, stock, 16, x);
	else
		tmp = ft_utoa_base(x, 16);
	if (x != 0 && ((*stock)->to_flag & TO_CONVERT) && (*stock)->field == 0)
		tmp = ft_search_flag_for_flag_convert(stock, tmp);
	else if (x != 0 && ((*stock)->to_flag & TO_CONVERT))
		tmp = ft_search_flag_for_flag_convert(stock, tmp);
	to_print = ft_strlen(tmp);
	if (x != 0 && (ft_search_flag_for_conver(stock, format, 'X') == 1))
		tmp = ft_str_upper(tmp);
	if ((*stock)->to_flag & TO_ZERO)
	{
		tmp = ft_flag_to_zero(stock, to_print, tmp, x);
		to_print = ft_flag_to_print(stock, to_print, x);
	}
	ft_order_all_flag(stock, to_print, tmp, x);
	(*stock)->ret = (*stock)->ret + ft_strlen(tmp);
	(*stock)->nb = (*stock)->nb + 1;
}

void	ft_print_if_neg(intmax_t x, t_flag **stock)
{
	if (x < 0)
		ft_putchar('-');
	(*stock)->ret = (*stock)->ret + 1;
}

int		ft_count_pres_long(t_flag **stock, wchar_t *str, int print_presi)
{
	while (str[print_presi] && (print_presi < (*stock)->stock_presi))
		print_presi++;
	return (print_presi);
}

char	*ft_tmp_zero(void)
{
	char *tmp;

	if ((tmp = (char *)malloc(sizeof(char) * 2)) == 0)
		return (NULL);
	ft_bzero(tmp, 2);
	tmp[0] = '0';
	return (tmp);
}

char	*ft_tmp_b_zero(void)
{
	char *tmp;

	if ((tmp = (char *)malloc(sizeof(char) * 2)) == 0)
		return (NULL);
	ft_bzero(tmp, 2);
	tmp[0] = '\0';
	return (tmp);
}
