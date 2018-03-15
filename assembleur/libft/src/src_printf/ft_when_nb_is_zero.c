/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_when_nb_is_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:00:17 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/02/22 20:04:44 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdlib.h>

char		*ft_if_nb_zero_1(char *tmp, t_flag **stock)
{
	if ((*stock)->presi == 1 && (*stock)->stock_presi == 0)
		tmp = ft_if_nb_zero_5(tmp, stock);
	else if ((*stock)->presi == 1 && (*stock)->stock_presi > 0)
	{
		(*stock)->ret = (*stock)->ret - 1;
		if ((*stock)->presi == 1 && (*stock)->stock_presi > 0)
		{
			tmp = ft_tmp_b_zero();
			if (!(((*stock)->to_flag & TO_ADD) && \
				((*stock)->to_flag & TO_ESPACE)))
			{
				(*stock)->presi = (*stock)->presi - 1;
				(*stock)->field = (*stock)->field + 1;
			}
		}
		else
			tmp = ft_tmp_b_zero();
	}
	else
		tmp = ft_tmp_b_zero();
	return (tmp);
}

char		*ft_if_nb_zero_2(char *tmp, t_flag **stock)
{
	if ((*stock)->value == 'o' || (*stock)->value == 'O')
		tmp = ft_special_option_o(stock);
	else if ((*stock)->presi == 0)
		tmp = ft_tmp_zero();
	else
	{
		if ((*stock)->value != 'O')
			tmp = ft_tmp_b_zero();
		else if ((*stock)->value == 'O')
			tmp = ft_tmp_zero();
	}
	return (tmp);
}

char		*ft_if_nb_zero_3(char *tmp, t_flag **stock)
{
	if (((*stock)->field > 0))
	{
		if ((*stock)->presi == 0)
			tmp = ft_tmp_zero();
		else
			tmp = ft_if_nb_zero_1(tmp, stock);
	}
	else
	{
		if ((tmp = (char *)malloc(sizeof(char) * 1)) == 0)
			return (NULL);
		ft_bzero(tmp, 2);
		tmp[0] = ' ';
	}
	return (tmp);
}

char		*ft_if_nb_zero_4(char *tmp, t_flag **stock)
{
	if ((tmp = (char *)malloc(sizeof(char) * (3))) == 0)
		return (NULL);
	ft_bzero(tmp, 3);
	if ((*stock)->to_flag & TO_CONVERT)
	{
		tmp[0] = '0';
		tmp[1] = '1';
	}
	else
		tmp[0] = '1';
	return (tmp);
}

char		*ft_if_nb_is_zero(int nb, t_flag **stock, int base, intmax_t x)
{
	char *tmp;

	tmp = NULL;
	nb = 1;
	if (base < 2 || base > 16)
		return (NULL);
	if (((*stock)->to_flag & TO_ADD) || ((*stock)->to_flag & TO_ESPACE))
		(*stock)->field = (*stock)->field - 1;
	if ((!((*stock)->to_flag & TO_CONVERT)) && (*stock)->value == 'O' && x == 1)
	{
		if ((tmp = (char *)malloc(sizeof(char) * (3))) == 0)
			return (NULL);
		ft_bzero(tmp, 3);
		tmp[0] = '1';
	}
	else if ((*stock)->value == 'O' && x == 1)
		tmp = ft_if_nb_zero_4(tmp, stock);
	else if ((*stock)->zero_field_more == 1)
		tmp = ft_if_nb_zero_3(tmp, stock);
	else
		tmp = ft_if_nb_zero_2(tmp, stock);
	return (tmp);
}
