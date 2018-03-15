/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lane_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 11:06:09 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 15:57:45 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	check les parametres
*/

int			check_char_args(char *line, int *i, int *x, char **tmp)
{
	if (line[*i + *x] && line[*i + *x] == SEPARATOR_CHAR)
	{
		if (check_separator(line, i, x, tmp) == -1)
			return (-1);
	}
	else if (line[*i + *x] && line[*i + *x] == '-')
	{
		if (check_separator_neg(line, i, x, tmp) == -1)
			return (-1);
	}
	else if (line[*i + *x] && (line[*i + *x] == \
				LABEL_CHAR || line[*i + *x] == '%'))
	{
		(*tmp)[*x] = line[*i + *x];
		(*x)++;
	}
	else if (line[*i + *x] && (!(if_is_label_chars(line[*i + *x]) == 1)))
		return (check_if_zero(line, i, x, tmp));
	else
	{
		(*tmp)[*x] = line[*i + *x];
		(*x)++;
	}
	return (1);
}

int			pars_check_arg(char *line, int *i, int *x, char **tmp)
{
	int o;

	o = ft_strlen(line);
	while ((*i + *x) < o)
	{
		*i = after_space(line, *i + *x) - *x;
		if (line[*i + *x] && line[*i + *x] == '#')
			break ;
		while (line[*i + *x] && line[*i + *x] != ' ' && line[*i + *x] != '\t')
		{
			if ((check_char_args(line, i, x, tmp)) == -1)
				ft_exit(1, "Wrong args\n");
		}
	}
	return (1);
}

int			parse_check_upcode(char *line, int *i, int *x, char **tmp)
{
	while (*i + *x < ft_strlen(line) && line[*i + *x]
			&& line[*i + *x] != ' ' && line[*i + *x] != '\t')
	{
		if (line[*i + *x] && line[*i + *x] == '#')
			return (put_b_zero(tmp, line, i, x));
		else if (line[*x + *i] && !((line[*i + *x] >= 'a' &&
						line[*i + *x] <= 'z')))
			ft_exit(1, "Upcode does not exist\n");
		(*tmp)[*x] = line[*i + *x];
		(*x)++;
	}
	(*tmp)[*x] = ' ';
	(*x)++;
	return (1);
}

void		put_space_string(char *line, int *x, char **tmp)
{
	char	*w;
	char	*p;

	w = NULL;
	p = NULL;
	if (!(*tmp)[*x])
	{
		w = ft_strnew(ft_strlen(line) + 2);
		p = (*tmp);
		w = ft_strcpy(w, (*tmp));
		w[*x] = ' ';
		(*x)++;
		(*tmp) = w;
		free(p);
	}
	else
	{
		(*tmp)[*x] = ' ';
		(*x)++;
	}
}

/*
**	return (0) si label sinon la position du label
*/

int			parse_check_if_label(char *line, int *i, int *x, char **tmp)
{
	int label;

	label = 0;
	while (*i + *x < ft_strlen(line) && line[*i + *x] \
			&& line[*i + *x] != ' ' && line[*i + *x] != '\t')
	{
		if (line[*i + *x] == '#')
			ft_exit(1, "no good param\n");
		else if (line[*i + *x] == LABEL_CHAR && ((label = 1)))
		{
			(*tmp)[*x] = line[*i + *x];
			(*x)++;
			break ;
		}
		else if ((continue_check_label(line, i, x, tmp)) == 1)
			return (1);
	}
	if (line[*x + *i] == '#')
	{
		if (label != 1)
			*x = 0;
		return (put_b_zero(tmp, line, i, x));
	}
	(label != 1) ? (*x = 0) : put_space_string(line, x, tmp);
	return (1);
}
