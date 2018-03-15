/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_name_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:18:06 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 18:43:47 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**regarde ce qu'il y a entre la 2eme quote et espace puis
*/

void		check_after_quote(char *line, int quote, int x)
{
	int i;
	int ref;
	int s;

	s = 0;
	i = 0;
	ref = 0;
	if ((ref = ft_strclen(line, '#')) > 0)
		x++;
	else
		ref = ft_strlen(line);
	i = 1 + ft_strclen(line + i, '"');
	if (quote > 1)
	{
		while (line[i + s] && line[i + s] != '"')
			s++;
		s++;
	}
	while (line[i + s] && (i + s < ref))
	{
		if (!(is_space_tab(line[i + s])))
			ft_exit(1, "Syntax error after name or comment\n");
		i++;
	}
}

/*
**regarde si il y a bien deux double quote dans line
*/

void		check_lenght_name(char *line, int len_max)
{
	int i;
	int x;

	x = 0;
	i = 0;
	i = ft_strclen(line, '"');
	i++;
	x = ft_strclen(line + i, '"');
	if ((x - i) >= len_max)
		ft_exit(1, ".name too long\n");
}

/*
**recoie les infos de bases pour pouvoir savoir comment dire
**si le parsing du nom ou commentaire est en cour ou
**si un des est fini ou si les deux sont finis
*/

void		where_we_are_in_parsing_name_comment(t_asm *tmp, int macro, int ref)
{
	tmp->ref.name = tmp->ref.name | macro;
	if ((tmp->ref.name & NAME_OK) \
			&& ((tmp->ref.name & COMMENT_OK)))
		tmp->ref.name = tmp->ref.name | NAME_COMMENT_END;
	if (ref == CASE_NAME && tmp->ref.name & PARSE_NAME)
		tmp->ref.name = tmp->ref.name - 2;
	else if (ref == CASE_COMMENT && tmp->ref.name & PARSE_COMMENT)
		tmp->ref.name = tmp->ref.name - 8;
}
