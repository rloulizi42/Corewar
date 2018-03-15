/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_chech_begin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:51:35 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/11 20:01:29 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_separator(char *line, int *i, int *x, char **tmp)
{
	if (check_separator_char(line, *i + *x, SEPARATOR_CHAR) == 0)
	{
		(*i)++;
		return (-1);
	}
	else if (check_separator_char(line, *i + *x, SEPARATOR_CHAR) == 1)
	{
		(*tmp)[*x] = ' ';
		(*x)++;
	}
	else
		(*i)++;
	return (1);
}

int			check_separator_neg(char *line, int *i, int *x, char **tmp)
{
	if (line[*x + *i + 1] && !(ft_isdigit(line[*x + *i + 1])))
		return (-1);
	if (line[*x + *i] && check_separator_char(line, *x + *i, '-') == 0)
		return (-1);
	else if (line[*x + *i + 1] && check_separator_char(line, *x + *i, '-') == 1)
	{
		(*tmp)[*x] = line[*i + *x];
		(*x)++;
	}
	else
		(*i)++;
	return (1);
}

int			exit_file(char *line)
{
	ft_putendl(line);
	exit(1);
	return (-1);
}

int			check_name(char *line)
{
	int x;
	int s;

	s = 0;
	x = ft_strlen(line);
	if (line[x - 2] != '.' && line[x - 1] != 's')
		ft_exit(1, "The file is not a .s file\n");
	return (1);
}

int			check_open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (check_name(argv) == -1)
		return (-1);
	if (fd < 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	return (fd);
}
