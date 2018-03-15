/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 22:03:07 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/12/13 18:08:38 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <wchar.h>

void	ft_convert_1(char *format, t_flag **stock, va_list ap, int i)
{
	if (format[i] && (format[i] == 'x' || format[i] == 'X'))
		ft_option_x(stock, ap, format);
	else if (format[i] && (format[i] == 'o' || format[i] == 'O'))
		ft_option_o(stock, ap, format);
	else if (format[i] && (format[i] == 'p'))
		ft_option_p(stock, ap);
	else if (format[i] && (format[i] == '%'))
		ft_print_percent(stock);
	else
		(*stock)->error++;
}

void	ft_convert(char *format, t_flag **stock, va_list ap)
{
	int i;

	i = (*stock)->nb + 1;
	if (format[i] && format[i] == 'c')
		ft_char_c(stock, ap);
	else if (format[i] && format[i] == 'C')
		ft_char_c_c(format, stock, ap);
	else if (format[i] && format[i] == 's')
		ft_char_s(stock, ap);
	else if (format[i] && format[i] == 'S')
		ft_char_s_s(stock, ap);
	else if (format[i] && (format[i] == 'd' || format[i] == 'i'))
		ft_option_d(stock, ap);
	else if (format[i] && (format[i] == 'D' || format[i] == 'u'\
				|| format[i] == 'U'))
		ft_option_d_d(stock, ap);
	else
		ft_convert_1(format, stock, ap, i);
}

char	*ft_if_nb_zero_5(char *tmp, t_flag **stock)
{
	tmp = ft_tmp_b_zero();
	(*stock)->field = (*stock)->field + 1;
	if ((*stock)->value == 'x' || (*stock)->value == 'X' ||
			(*stock)->value == 'u' || (*stock)->value == 'O' ||
			(*stock)->value == 'o' || (*stock)->value == 'U')
		(*stock)->ret = (*stock)->ret + 1;
	(*stock)->ret = (*stock)->ret - 1;
	return (tmp);
}
