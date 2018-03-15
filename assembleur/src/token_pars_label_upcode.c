/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_pars_label_upcode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:32:42 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 18:06:03 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			if_is_label_chars(char line)
{
	if (line >= 'a' && line <= 'z')
		return (1);
	if (line >= '0' && line <= '9')
		return (1);
	if (line == '_')
		return (1);
	if (line == '\t' || line == ' ')
		return (2);
	return (0);
}

/*
**  return > 0 si il commence par un label sinon -1
*/

int			is_no_char_begin_label(char *line, t_lst_asm **lst, int *i)
{
	if ((ft_strlen(line)) == *i)
	{
		(*lst)->label_instruc |= ONLY_LABEL;
		return (*i);
	}
	else
		return (((if_is_label_chars(line[*i]))) ? (*i) : 0);
}

int			is_begin_by_label(char *line, t_lst_asm **lst)
{
	int i;
	int x;

	i = 0;
	x = ft_strclen(line, ':');
	while (i <= x)
	{
		if (line[i] && line[i] == ' ')
		{
			if (i - 1 >= 0 && line[i - 1] != ':')
				(*lst)->label_instruc |= INSTRUC;
			return (0);
		}
		else if (!(if_is_label_chars(line[i])))
		{
			if (line[i] == ':')
				i++;
			while (is_space_tab(line[i]))
				i++;
			return (is_no_char_begin_label(line, lst, &i));
		}
		i++;
	}
	return (-1);
}

/*
**  return > 0 si il le param est un upcode sinon -1 == erreur fichier
*/

int			what_upcode_is(int i, char *line, t_lst_asm **lst)
{
	int x;
	int stock;

	x = 0;
	if (i > 0)
		(*lst)->label_instruc |= LABEL_INSTRUC;
	else
		(*lst)->label_instruc |= INSTRUC;
	if (line[i] && line[i] == '%')
		i++;
	if (line[i] && line[i] == ':')
		i++;
	while ((g_op_tab[x]).label)
	{
		if ((ft_strncmp(line + i, g_op_tab[x].label, g_op_tab[x].len_cmp)) == 0)
		{
			stock = i + g_op_tab[x].len_cmp;
			(*lst)->tab = x;
			return (stock);
		}
		x++;
	}
	return (-1);
}
