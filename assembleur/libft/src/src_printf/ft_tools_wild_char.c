/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_wild_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:15:08 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/12/13 18:09:38 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <wchar.h>

/*
****decale de 6>>car 110xxxxx 10xxxxxx se retrouve apres le 10
****decale de >>12 car 1110xxxx 10xxxxxx 10xxxxxx se retrouve apres le 10
****decale de >>18 car 11110xxx 10xxxxxx
****10xxxxxx 10xxxxxx se retrouve apres le 10
*/

int			ft_strwlen(wchar_t *str)
{
	int			i;
	intmax_t	x;

	x = 0;
	i = 0;
	while (str[x])
	{
		i = i + ft_wchar_len(str[x]);
		x++;
	}
	return (i);
}

int			ft_putwstr(wchar_t *str, t_flag **stock)
{
	wchar_t i;

	i = 0;
	while (str[i])
	{
		if (ft_putwchar(str[i]) == 1)
			(*stock)->ret = (*stock)->ret + ft_wchar_len(str[i]);
		else
		{
			(*stock)->error++;
			return (-1);
		}
		i++;
	}
	return (1);
}

int			ft_wchar_len(wchar_t chr)
{
	if (chr <= 0x7F && MB_CUR_MAX >= 1)
		return (1);
	else if (chr <= 0x7FF)
	{
		if (chr <= 0xFF && MB_CUR_MAX == 1)
			return (1);
		else if (MB_CUR_MAX >= 2)
			return (2);
		else
			return (2);
	}
	else if (chr <= 0xFFFF && MB_CUR_MAX >= 3)
		return (3);
	else if (chr <= 0x10FFFF && MB_CUR_MAX >= 4)
		return (4);
	return (-1);
}

void		ft_putchar_big_char(wchar_t chr)
{
	ft_putchar((unsigned char)(chr >> 18) + 0xF0);
	ft_putchar((unsigned char)((chr >> 12) & 0x3F) + 0x80);
	ft_putchar((unsigned char)((chr >> 6) & 0x3F) + 0x80);
	ft_putchar((unsigned char)(chr & 0x3F) + 0x80);
}

int			ft_putwchar(wchar_t chr)
{
	if ((chr <= 0x7F) && (MB_CUR_MAX >= 1))
		ft_putchar((unsigned char)chr);
	else if (chr <= 0x7FF)
	{
		if (chr <= 0xFF && MB_CUR_MAX == 1)
			ft_putchar((unsigned char)chr);
		else if (chr <= 0x7FF && MB_CUR_MAX >= 2)
		{
			ft_putchar((unsigned char)(chr >> 6) + 0xC0);
			ft_putchar((unsigned char)(chr & 0x3F) + 0x80);
		}
		else
			return (-1);
	}
	else if (chr <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		ft_putchar((unsigned char)(chr >> 12) + 0xE0);
		ft_putchar((unsigned char)((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((unsigned char)(chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF && MB_CUR_MAX >= 4)
		ft_putchar_big_char(chr);
	else
		return (-1);
	return (1);
}
