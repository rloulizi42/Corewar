/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:07:07 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/22 14:11:15 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		open_file_for_fd(void)
{
	int fd;

	fd = 0;
	if (((fd = open("./files/a", O_CREAT & O_RDWR, S_IRWXO)) == -1) \
			|| read(fd, NULL, 0) < 0)
	{
		ft_putstr("error open create_file_stdin\n");
	}
	return (fd);
}
