/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:17:07 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 15:40:53 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			len_name(char *line, int rf, int pos_sec_quot)
{
	int i;
	int stock;

	i = 0;
	stock = 0;
	stock = (rf == CASE_NAME) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	while (line[i] && line[i] != ('"'))
	{
		i++;
	}
	if (((stock) - (pos_sec_quot - i)) < 0)
		ft_exit(1, "Wrong name/comment length\n");
	return (1);
}

/*
**check	qu'il a pas de betises apres le name et avant la 1er quote
*/

void		check_after_name(char *line, int ref)
{
	int		i;
	int		x;
	char	*stock;

	stock = (ref == CASE_NAME) ? ".name" : ".comment";
	i = 0;
	x = 0;
	i = ft_strclen(line, '"');
	while (is_space_tab(line[x]))
		x++;
	x = x + 1 + ft_strrclen(line, stock);
	while (x < i)
	{
		if ((!(is_space_tab(line[x]))) && line[x] != '"')
			ft_exit(1, ".name not well formated\n");
		x++;
	}
}

/*
**les fonctions check la 1er ligne car cela sera le cas le plus normal
*/

static	int	check_begin_name(char *line, int i, int rf)
{
	int		x_ref;
	char	*stock;

	x_ref = (rf == CASE_NAME) ? 4 : 7;
	stock = (rf == CASE_NAME) ? ".name" : ".comment";
	if (((ft_strclen(line, '"')) == 0))
		ft_exit(1, ".name not well formated\n");
	while ((is_space_tab(line[i])))
		i++;
	if (line[i] == COMMENT_CHAR || line[i] != '.')
		ft_exit(1, ".name not well formated\n");
	if ((ft_strncmp((line + i), stock, ft_strlen(stock)) != 0))
		ft_exit(1, ".name at wrong place\n");
	i = (ft_strclen(line, '"'));
	return (i);
}

/*
**check si il y a plusieurs quote > 2 dans la line	sinon renvoie le
**nb de quote pour savoir dans quel cas on est si cas 1 ou cas 2
*/

int			pars_first_line_name(char *line, int rf)
{
	int i;
	int x;

	x = 0;
	i = 0;
	i = check_begin_name(line, i, rf);
	check_after_name(line, rf);
	while ((is_space_tab(line[i])))
		i++;
	if (line[i] == ('"'))
	{
		x = 1;
		i++;
		while (line[i])
		{
			if ((line[i] == ('"')) && x == 1 && len_name(line, rf, i - 1))
				x = 2;
			else if ((line[i] == ('"')) && x == 2)
				ft_exit(1, ".name or .comment not well formated\n");
			i++;
		}
	}
	else
		ft_exit(1, ".name or .comment not well formated\n");
	return ((x == 2) ? 2 : 1);
}
