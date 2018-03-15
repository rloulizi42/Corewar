/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:29:49 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/11 16:53:05 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		after_space(char *line, int i)
{
	int x;

	x = ft_strlen(line);
	while (i < x && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

int		is_arg(char c)
{
	if (c == 'r' || c == '%' || c == ':' || c == ',')
		return (1);
	return (0);
}

int		ft_striflen(const char *str, char c)
{
	int		i;
	int		ref;

	ref = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	else
		return (0);
}

int		ft_strnncmp(const char *str, char *cmp, int nb_to_check)
{
	int		i;
	int		stock;

	stock = 0;
	i = 0;
	if (ft_strlen(cmp) == 12)
	{
		if (ft_isdigit(str[i]) || str[0] == '+' || str[0] == '-')
			return (1);
	}
	i = 0;
	while (str[i] && nb_to_check > 0)
	{
		if (str[i] == cmp[stock])
		{
			nb_to_check--;
			i++;
			stock++;
		}
		else
			return (0);
	}
	return ((nb_to_check == 0) ? 1 : 0);
}
