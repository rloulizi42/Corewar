/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:15:58 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/10 12:21:24 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			ft_exit(int i, char *line)
{
	ft_putstr(line);
	exit(i);
}

/*
**regarde si il a une occurence entre les deux
*/

int				ft_str_is(char *line, char c)
{
	size_t	i;
	int		x;

	x = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			x++;
		i++;
	}
	return ((x == 1) ? 1 : 0);
}

/*
**envoir la 1er ligne la plus longue et la seconde a trouver
**dans la 1er si ok retourne la pos de la plus longue chaine
** si ne trouve rien renvoie -1 s'utilise dans le cas de comparaison
**pour avoir des position d'adresse entre des chaine de chars
*/

int				ft_strrschr(char *s1, char *s2)
{
	int i;
	int	j;
	int	len;

	len = 0;
	len = ft_strlen(s2);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			j = 0;
			while (s1[i + j] && s2[j] && s1[i + j] == s2[j])
				j++;
			if (j == len)
				return (i);
			j = 0;
		}
		i++;
	}
	return (-1);
}

/*
**compare la 1er et seconde et renvoir si s2 est dans s1
**l'int correspondant a la fin
*/

int				ft_strrclen(char *s1, char *s2)
{
	int i;
	int	j;
	int	len;

	len = 0;
	len = ft_strlen(s2);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			j = 0;
			while (s1[i + j] && s2[j] && s1[i + j] == s2[j])
				j++;
			if (j == len)
				return (j);
			j = 0;
		}
		i++;
	}
	return (-1);
}
