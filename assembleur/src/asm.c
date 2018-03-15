/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:47:38 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 19:14:10 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**parse la 1er ligne et si il y a 2 double quote ben top sinon copie
**le max en regardant la taille max tant qu'il ne depasse pas et attend
**le prochaine GNL
*/

int				get_name(char *line, t_asm *tmp, int ref)
{
	int			i;
	int			x;

	x = 0;
	i = 0;
	if (!(tmp->ref.name & PARSE_NAME))
	{
		i = pars_first_line_name(line, ref);
		if (i == MANY_LINES)
		{
			x = copy_not_only_one_string(line, tmp, ref);
			tmp->ref.name = tmp->ref.name | PARSE_NAME;
		}
		else if (i == ONLY_ONE_LINES)
		{
			check_lenght_name(line, PROG_NAME_LENGTH);
			x = copy_one_line(line, tmp, ref, NAME_OK);
		}
	}
	else if (!(tmp->ref.name & NAME_OK) && (tmp->ref.name & PARSE_NAME))
		x = copy_other_string(line, tmp, ref, NAME_OK);
	return (x);
}

int				get_comment(char *line, t_asm *tmp, int ref)
{
	int			i;
	int			x;

	x = 0;
	i = 0;
	if (!(tmp->ref.name & PARSE_COMMENT))
	{
		i = pars_first_line_name(line, ref);
		if (i == MANY_LINES)
		{
			x = copy_not_only_one_string(line, tmp, ref);
			tmp->ref.name = tmp->ref.name | PARSE_COMMENT;
		}
		else if (i == ONLY_ONE_LINES)
		{
			check_lenght_name(line, COMMENT_LENGTH);
			x = copy_one_line(line, tmp, ref, COMMENT_OK);
			tmp->ref.name = tmp->ref.name | COMMENT_OK;
		}
	}
	else if (!(tmp->ref.name & COMMENT_OK) && (tmp->ref.name & PARSE_COMMENT))
		x = copy_other_string(line, tmp, ref, COMMENT_OK);
	return (x);
}

int				parsing_name_comment(char *line, t_asm *tmp)
{
	int				i;

	i = 0;
	while ((is_space_tab(line[i])))
		i++;
	if ((tmp->ref.name & PARSE_NAME) && !(tmp->ref.name & PARSE_COMMENT) \
			&& !((tmp->ref.name & NAME_OK)))
		tmp->stock_name = tmp->stock_name + get_name(line, tmp, CASE_NAME);
	else if ((tmp->ref.name & PARSE_COMMENT) && \
			!(tmp->ref.name & PARSE_NAME) && !((tmp->ref.name & COMMENT_OK)))
		tmp->stock_comment = get_comment(line, tmp, CASE_COMMENT);
	else if (((ft_strncmp(line + i, NAME_CMD_STRING, 4) == 0 \
					&& !(tmp->ref.name & NAME_OK))))
		tmp->stock_name = tmp->stock_name + get_name(line, tmp, CASE_NAME);
	else if (((ft_strncmp(line + i, COMMENT_CMD_STRING, 7)) == 0) \
			&& !((tmp->ref.name & COMMENT_OK)))
		tmp->stock_comment = tmp->stock_comment + \
				get_comment(line, tmp, CASE_COMMENT);
	else if (line[i] == '#')
		return (1);
	else if (ft_strlen(line) && line[i] != '\n')
		ft_exit(1, "Wrong line format in header\n");
	return (1);
}
