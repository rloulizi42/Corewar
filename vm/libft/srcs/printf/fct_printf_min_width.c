/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_printf_min_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:05:27 by sflinois          #+#    #+#             */
/*   Updated: 2018/01/20 14:53:48 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

char	*apply_min_width(char *str, t_expr expr)
{
	int		n;
	char	*ret;

	if (!str)
		return (NULL);
	n = expr.min_width - ft_strlen(str);
	if (n <= 0 || (*str != 0 && expr.min_width == 1))
		return (str);
	else
	{
		if (!(ret = ft_strnew(sizeof(char) * expr.min_width)))
			return (NULL);
		while (n > 0)
		{
			n--;
			ret[n] = ' ';
		}
		ret = ft_strcat(ret, str);
		free(str);
	}
	return (ret);
}
