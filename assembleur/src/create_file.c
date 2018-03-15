/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:57:46 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/10 18:35:03 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		len_to_create(char *line)
{
	int i;
	int end;

	end = 0;
	i = ft_strlen(line);
	i--;
	if (!(line[i] == 's' && line[i - 1] == '.'))
		return (-1);
	i = i - 2;
	while (line[i - end] && line[i - end] != '/')
		end++;
	end--;
	return (i - (end - 1));
}

int		create_file(char *line)
{
	int		i;
	int		fd;
	char	*tmp;

	tmp = NULL;
	i = ft_strlen(line);
	tmp = ft_strndup(line, i - 1);
	tmp = ft_strjoin_free(tmp, "cor");
	if (tmp == NULL)
		return (-1);
	if ((fd = open(tmp, O_CREAT | O_WRONLY | O_TRUNC, 0664)) == 0)
		ft_exit(1, "Error while oppening file\n");
	free(tmp);
	return (fd);
}
