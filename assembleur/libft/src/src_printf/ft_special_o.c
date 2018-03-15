/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 00:20:29 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:26:11 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_special_o_o_o(t_flag **stock, char *tmp)
{
	if ((*stock)->value == 'o')
		tmp = ft_tmp_b_zero();
	else if ((*stock)->value == 'O')
		tmp = ft_tmp_zero();
	else
		tmp = ft_tmp_b_zero();
	return (tmp);
}

char	*ft_special_o_o(t_flag **stock, char *tmp)
{
	if ((*stock)->value == 'O')
		tmp = ft_tmp_zero();
	else
		tmp = ft_tmp_b_zero();
	return (tmp);
}

char	*special_o(t_flag **stock, char *tmp)
{
	if ((*stock)->value == 'O' && \
			(*stock)->presi == 0 && (*stock)->field == 0)
		tmp = ft_tmp_zero();
	else if ((*stock)->value == 'O' && \
			(*stock)->presi == 0 && (*stock)->field == 0)
		tmp = ft_tmp_zero();
	else if ((*stock)->value == 'o' && \
			(*stock)->presi == 0 && (*stock)->field == 0)
		tmp = ft_tmp_zero();
	else if (((*stock)->to_flag & TO_CONVERT) && \
			(*stock)->value == 'o' && \
			(*stock)->presi == 0 && (*stock)->field == 0)
		tmp = ft_tmp_zero();
	else
		tmp = ft_tmp_zero();
	return (tmp);
}

char	*ft_special_option_o(t_flag **stock)
{
	char *tmp;

	tmp = NULL;
	if ((*stock)->field == 0)
	{
		if (((*stock)->to_flag & TO_CONVERT) && (*stock)->presi == 1)
			tmp = ft_special_o_o(stock, tmp);
		else if (((*stock)->to_flag & TO_CONVERT) && (*stock)->presi == 0)
			tmp = ft_special_o_o_o(stock, tmp);
		else if ((*stock)->presi == 1 && (*stock)->field == 0)
			tmp = ft_tmp_b_zero();
		else
			tmp = special_o(stock, tmp);
	}
	else if ((*stock)->field > 0)
		tmp = ft_tmp_zero();
	else
		tmp = ft_tmp_zero();
	return (tmp);
}
