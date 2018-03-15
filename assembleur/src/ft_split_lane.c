/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:51:12 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 15:56:44 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	return 0 si il y a le meme avant
**	return 1 si il y avait rien avant
*/

int		check_separator_char(char *line, int i, char ref)
{
	i--;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i--;
	return ((line[i] == ref) ? 0 : 1);
}

int		check_if_upcode_after_label(int i, char *line)
{
	while (is_space_tab(line[i]))
		i++;
	if (line[i] == ':')
		i++;
	while (line[i] && is_space_tab(line[i]))
		i++;
	if (!(line[i]))
		return (0);
	else if (line[i] && line[i] == '\0')
		return (0);
	else if (line[i] && (line[i] == '#' || line[i] == '/'))
		return (0);
	else if (line[i] && (line[i] >= 'a' && line[i] <= 'z'))
		return (1);
	else
		ft_exit(1, "Wrong char\n");
	return (1);
}

/*
** copie sans les espaces ou 1 seul entre les 2
*/

void	fill_tmp(char *tmp, int *i)
{
	if (tmp[*i] && tmp[*i] == ':')
		(*i)++;
	if (tmp[*i] && is_space_tab(tmp[*i]))
		tmp[*i] = ' ';
	(*i)++;
	if (tmp[*i] && tmp[*i] != '\0')
		tmp[*i] = '\0';
}

char	*copy_string_witout_space_tab(char *tmp, char *line)
{
	int i;
	int x;
	int label;

	label = 0;
	x = 0;
	i = after_space(line, 0);
	if (parse_check_if_label(line, &i, &x, &tmp) == -1)
		ft_exit(1, "Label does not exist\n");
	i = after_space(line, i + x) - x;
	if ((check_if_upcode_after_label(i, line) == 1))
	{
		if (parse_check_upcode(line, &i, &x, &tmp) == -1)
			ft_exit(1, "Upcode does not exist\n");
		i = after_space(line, i + x) - x;
		if (pars_check_arg(line, &i, &x, &tmp) == -1)
			ft_exit(1, "Wrong args\n");
	}
	else
		fill_tmp(tmp, &i);
	return (tmp);
}

/*
**  ne copie que la string et 1 seul esp/tab entre 2 mots
*/

char	*split_line(char *line)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	if (((len = ft_strlen(line)) < 0))
		ft_exit(1, "Instruction not well formated\n");
	if ((tmp = ft_strnew(len + 2)) == NULL)
		ft_exit(1, "Malloc error (split_list)\n");
	if ((tmp = copy_string_witout_space_tab(tmp, line)) == NULL)
		ft_exit(1, "Instruction not well formated\n");
	return (tmp);
}
