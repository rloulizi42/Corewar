/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content_name_comment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:34:32 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 19:16:33 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**copie les lignes d'apres apres le  1er back slach n qui ont en plusieurs
*/

int			copy_other_string(char *line, t_asm *tmp, int ref, int macro)
{
	int		i;
	int		j;
	int		len_max;
	char	*str;

	i = 0;
	j = 0;
	len_max = (ref == CASE_NAME) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	str = (ref == CASE_NAME) ? tmp->head.prog_name : tmp->head.comment;
	while (str[i])
		i++;
	if ((ft_str_is(line, '"') > 0) || line[0] == '"')
	{
		check_after_quote(line, 1, 0);
		where_we_are_in_parsing_name_comment(tmp, macro, ref);
	}
	while (i < len_max && line[j] && line[j] != '"')
		str[i++] = line[j++];
	check_len(str, ref);
	if (line[j] != '\0')
		check_after_quote(line, 1, 0);
	return (j);
}

/*
**cas ou il y a qu'une seule ligne
*/

int			copy_one_line(char *line, t_asm *tmp, int ref, int macro)
{
	int		i;
	int		j;
	int		len_max;
	char	*str;

	i = 0;
	j = 0;
	len_max = (ref == CASE_NAME) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	str = (ref == CASE_NAME) ? tmp->head.prog_name : tmp->head.comment;
	while (str[i])
		i++;
	check_if_no_point(line, &j);
	j = 1 + ft_strclen(line, '"');
	check_after_before_quote(line, j, ref);
	if (((ft_strclen(line + j, '"') - j) > len_max))
		ft_exit(1, ".comment too long\n");
	while (i < len_max && line[j] && line[j] != '"')
	{
		str[i] = line[j];
		i++;
		j++;
	}
	where_we_are_in_parsing_name_comment(tmp, macro, ref);
	check_after_quote(line, 2, 0);
	return (j);
}

/*
**cas ou il y a plusieurs ligne \n et la 1er ok
*/

int			after_while(char *str, int i)
{
	while (str[i])
		i++;
	return (i);
}

int			copy_not_only_one_string(char *line, t_asm *tmp, int ref)
{
	int		i;
	int		j;
	int		len_max;
	char	*str;

	i = 0;
	j = 0;
	len_max = (ref == CASE_NAME) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	str = (ref == CASE_NAME) ? tmp->head.prog_name : tmp->head.comment;
	i = after_while(str, i);
	j = 1 + ft_strclen(line, '"');
	check_after_before_quote(line, j, ref);
	while (i < len_max && line[j])
	{
		str[i] = line[j];
		i++;
		j++;
	}
	fill_b_space(&str, &i, len_max);
	if (ft_strlen(line + j) > 0)
		ft_exit(1, ".name too long\n");
	return (j);
}
