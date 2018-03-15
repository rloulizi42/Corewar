/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:00:15 by kkhalfao          #+#    #+#             */
/*   Updated: 2016/12/14 19:22:53 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int i;

	i = 0;
	if (s)
	{
		ft_putstr_fd(&s[i], fd);
		ft_putchar_fd('\n', fd);
	}
}
