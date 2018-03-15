/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:48:17 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/02/22 20:03:28 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int			ft_order(t_list **tmp, char **line, t_list **list)
{
	char	*str;
	char	*line_2;

	line_2 = *line;
	str = (char *)(((**(&tmp))->content));
	if ((*tmp)->content && ft_strchr((*tmp)->content, '\n'))
	{
		*line = ft_strndup((*tmp)->content, ft_strclen((*tmp)->content, '\n'));
		(**(&tmp))->content = ft_strdup(((*tmp)->content) +\
				(ft_strclen((*tmp)->content, '\n') + 1));
		free(str);
		*tmp = *list;
		return (1);
	}
	else if (str[0] != '\0')
	{
		*line = ft_strdup((*tmp)->content);
		ft_bzero((*tmp)->content, ft_strlen((*tmp)->content));
		return (1);
	}
	return (0);
}

t_list		*ft_return_block(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*secure;

	secure = *list;
	if (*list)
	{
		while (*list)
		{
			if (*list)
			{
				if ((int)((*list)->content_size) == fd)
				{
					tmp = (*list);
					(*list) = secure;
					return (tmp);
				}
				*list = (*list)->next;
			}
		}
	}
	*list = secure;
	tmp = ft_lstnew("", 1);
	tmp->content_size = fd;
	ft_lstadd(*(&list), tmp);
	return (**(&list));
}

int			get_next_line(int fd, char **line)
{
	int				ret;
	char			*buf;
	t_list			*tmp;
	static t_list	*list = NULL;
	t_list			*begin_list;

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line || \
			((buf = (char *)malloc(sizeof(*buf) * BUFF_SIZE + 1)) == 0))
		return (-1);
	begin_list = list;
	tmp = ft_return_block(&list, fd);
	while (!(ft_strchr(tmp->content, '\n')) \
			&& ((ret = read(fd, buf, BUFF_SIZE))))
	{
		buf[ret] = '\0';
		tmp->content = ft_strjoin_free(tmp->content, buf);
	}
	free(buf);
	if ((ft_order(&tmp, line, &begin_list)) == 1)
		return (1);
	return (0);
}
