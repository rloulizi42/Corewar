/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:29:32 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/06/16 01:21:14 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <unistd.h>
# include <stdio.h>
# include <string.h>

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define BUFF_SIZE 1

int			get_next_line(int fd, char **line);
t_list		*ft_return_block(t_list **list, int fd);
int			ft_order(t_list **tmp, char **line, t_list **list);

char		*ft_strjoin_free(char *str, char *buf);
char		*ft_strndup(const char *s1, int n);
int			ft_strclen(const char *str, int c);
#endif
