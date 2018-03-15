/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_for_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:52:08 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/04 03:52:11 by kkhalfao         ###   ########.fr       */
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

uintmax_t	ft_search_convert_d_d_d_d(t_flag **stock, va_list ap)
{
	uintmax_t x;

	x = (uintmax_t)va_arg(ap, uintmax_t);
	if ((*stock)->convert & TO_H)
		x = (unsigned short)x;
	else if ((*stock)->convert & TO_HH)
		x = (unsigned char)x;
	else if ((*stock)->convert & TO_L)
		x = (unsigned long)x;
	else if ((*stock)->convert & TO_LL)
		x = (unsigned long long)x;
	else if ((*stock)->convert & TO_J)
		x = (uintmax_t)x;
	else if ((*stock)->convert & TO_Z)
		x = (size_t)x;
	else if ((*stock)->value == 'U' || (*stock)->value == 'O')
		x = (unsigned long int)x;
	else if ((*stock)->value == 'o')
		x = (unsigned int)x;
	else if ((*stock)->value == 'D')
		x = (long int)x;
	else
		x = (unsigned int)x;
	return (x);
}

intmax_t	ft_search_convert_d(t_flag **stock, va_list ap)
{
	intmax_t x;

	x = (intmax_t)va_arg(ap, intmax_t);
	if ((*stock)->convert & TO_H)
		x = (short)x;
	else if ((*stock)->convert & TO_HH)
		x = (signed char)x;
	else if ((*stock)->convert & TO_L)
		x = (long)x;
	else if ((*stock)->convert & TO_LL)
		x = (long long)x;
	else if ((*stock)->convert & TO_J)
		x = (intmax_t)x;
	else if ((*stock)->convert & TO_Z)
		x = (size_t)x;
	else
		x = (int)x;
	return (x);
}

int			ft_search_flag_for_conver(t_flag **stock, char *format, int x)
{
	if (format[(*stock)->nb + 1] == x)
		return (1);
	return (0);
}

char		*ft_str_upper(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] >= 'a' && tmp[i] < 'z')
			tmp[i] = tmp[i] - 32;
		i++;
	}
	return (tmp);
}
