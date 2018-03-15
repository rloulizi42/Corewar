/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_pars_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:01:35 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/09 19:04:48 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int					ft_strxcmp(const char *s1, const char *s2, int n)
{
	int				max;
	unsigned char	*ss1;
	unsigned char	*ss2;

	max = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 == *ss2 && n >= 0 && *ss1 && *ss2)
	{
		ss1++;
		ss2++;
		n--;
	}
	if (*ss2)
		return (-1);
	return ((n == 0) ? 0 : -1);
}

void				get_ocp(t_lst_asm **lst, int nb_param, int ocp)
{
	const int tab[3] = {6, 4, 2};

	(*lst)->ocp = (*lst)->ocp | ocp << tab[nb_param];
	(*lst)->ocp = (*lst)->ocp >> 2;
	(*lst)->ocp = (*lst)->ocp << 2;
}

long long int		ft_atoi_lld(const char *str)
{
	int				neg;
	int				i;
	long long int	res;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	neg = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (str[neg] == '-') ? -res : res;
}
