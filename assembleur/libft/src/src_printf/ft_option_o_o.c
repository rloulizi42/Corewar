/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:23:36 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 02:08:41 by kkhalfao         ###   ########.fr       */
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
#include <string.h>
#include <stdarg.h>

char	*ft_replace_zero(t_flag **stock, char *tmp, int nb_zero)
{
	int		i;
	char	*tmp_2;

	tmp = NULL;
	i = 0;
	if ((tmp_2 = ft_strnew(nb_zero)) == 0)
	{
		(*stock)->error++;
		return (NULL);
	}
	while (nb_zero > 0)
	{
		tmp_2[i] = '0';
		i++;
		nb_zero--;
	}
	return (tmp_2);
}

int		ft_search_zero_for_convert(t_flag **stock, char *tmp, int nb_zero)
{
	nb_zero = ft_strlen(tmp);
	if ((*stock)->field > ft_strlen(tmp))
	{
		if ((*stock)->value == 'x')
			nb_zero = nb_zero + 2;
		else if ((*stock)->value == 'X')
			nb_zero = nb_zero + 2;
		else if ((*stock)->value == 'o')
			nb_zero = nb_zero + 1;
	}
	nb_zero = (*stock)->field - nb_zero;
	return (nb_zero);
}

char	*ft_search_flag_for_flag_convert(t_flag **stock, char *tmp)
{
	char	*tmp_zero;
	int		nb_ze;

	nb_ze = 0;
	if ((nb_ze = ft_search_zero_for_convert(stock, tmp, nb_ze)) > 0)
	{
		if ((*stock)->to_flag & TO_ZERO)
		{
			tmp_zero = ft_replace_zero(stock, tmp, nb_ze);
			tmp = ft_strjoin(tmp_zero, tmp);
		}
	}
	if ((*stock)->value == 'x')
		tmp = ft_strjoin("0x", tmp);
	else if ((*stock)->value == 'X')
		tmp = ft_strjoin("0X", tmp);
	else if ((*stock)->value == 'o')
		tmp = ft_strjoin("0", tmp);
	return (tmp);
}

void	ft_option_o(t_flag **stock, va_list ap, char *format)
{
	intmax_t	x;
	int			to_print;
	char		*tmp;

	tmp = NULL;
	x = ft_search_convert_d_d_d_d(stock, ap);
	to_print = ft_len_u_number(x, 8);
	if (x == 0 || ((*stock)->value == 'O' && x == 1))
		tmp = ft_if_nb_is_zero(to_print, stock, 8, x);
	else
		tmp = ft_utoa_base(x, 8);
	if ((*stock)->to_flag & TO_CONVERT)
		tmp = ft_search_flag_for_flag_convert(stock, tmp);
	to_print = ft_strlen(tmp);
	if (x != 0 && (ft_search_flag_for_conver(stock, format, 'O') == 1))
		tmp = ft_str_upper(tmp);
	if ((*stock)->to_flag & TO_ZERO)
	{
		tmp = ft_flag_to_zero(stock, to_print, tmp, x);
		to_print = ft_flag_to_print(stock, to_print, x);
	}
	ft_order_all_flag(stock, to_print, tmp, x);
	(*stock)->ret = (*stock)->ret + ft_strlen(tmp);
	(*stock)->nb = (*stock)->nb + 1;
	free(tmp);
}
