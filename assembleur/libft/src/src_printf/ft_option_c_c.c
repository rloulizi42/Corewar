/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_C_S.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:13:50 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 01:59:33 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <wchar.h>

void	ft_char_c_c(char *format, t_flag **stock, va_list ap)
{
	int		i;
	wchar_t c;

	c = (wint_t)va_arg(ap, wint_t);
	i = (*stock)->field - ft_wchar_len(c);
	if ((*stock)->field <= 1)
		i = 0;
	if (format[(*stock)->nb])
	{
		if (!((*stock)->to_flag & TO_RIGHT) && i > 0)
			ft_print_space(i, stock);
		if (ft_putwchar(c) == 1)
			(*stock)->ret = (*stock)->ret + ft_wchar_len(c);
		else
			(*stock)->error++;
		if ((*stock)->to_flag & TO_RIGHT)
			ft_print_space((i), stock);
	}
	(*stock)->nb = (*stock)->nb + 1;
}

void	ft_char_c(t_flag **stock, va_list ap)
{
	wint_t		c;
	intmax_t	i;

	c = 0;
	i = (*stock)->field - 1;
	if ((*stock)->field <= 1)
		i = 0;
	if ((*stock)->convert & TO_L)
		c = (wint_t)va_arg(ap, wint_t);
	else
		c = (wchar_t)va_arg(ap, wchar_t);
	if (!((*stock)->to_flag & TO_RIGHT) && i > 0)
		ft_print_space(i, stock);
	if (ft_putwchar(c) == 1)
		(*stock)->ret = (*stock)->ret + ft_wchar_len(c);
	else
		(*stock)->error++;
	if ((*stock)->to_flag & TO_RIGHT)
		ft_print_space((i), stock);
	(*stock)->nb = (*stock)->nb + 1;
}
