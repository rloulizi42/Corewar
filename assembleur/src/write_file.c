/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:17:37 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/10 19:46:31 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			write_ocp(char **tmp, int i, t_lst_asm **lst)
{
	int		end;
	int		exe;
	char	*ttp;

	end = i;
	if (!(((*lst)->tab == LIVE) || ((*lst)->tab == ZJUMP) \
				|| ((*lst)->tab == FORK) || ((*lst)->tab == LFORK)))
	{
		ttp = ft_itoa_base((*lst)->ocp, 16);
		exe = ft_atoi_base(ttp, 16);
		free(ttp);
		while ((i - end) >= 0)
		{
			(*tmp)[i] = exe;
			i--;
		}
		write((*lst)->fd, (*tmp) + end, 1);
		(*lst)->i = end + 1;
		return (end + 1);
	}
	return (end);
}

void		write_one_arg(char **tmp, int ref, t_lst_asm **lst)
{
	int		end;
	int		exe;
	char	*test;
	int		x;

	end = (*lst)->i + (*lst)->p[ref].chr - 1;
	test = ft_strdup((*lst)->p[ref].stock);
	x = ft_atoi_base(test, 16);
	exe = x;
	while ((end - (*lst)->i) >= 0)
	{
		(*tmp)[end] = exe;
		exe = exe >> 8;
		end--;
	}
	write((*lst)->fd, (*tmp) + (*lst)->i, (*lst)->p[ref].chr);
	(*lst)->i = (*lst)->i + (*lst)->p[ref].chr;
	free(test);
	if ((*lst)->p[ref].label)
		free((*lst)->p[ref].label);
}

void		write_all_arg(char **tmp, int fd, t_lst_asm **lst, int ref)
{
	int	stock_i;
	int	stock_fd;

	ref = 0;
	stock_i = 2192;
	stock_fd = fd;
	while (*lst)
	{
		((*lst)->fd = fd);
		if (((*lst)->label_instruc & LABEL_INSTRUC \
					|| (*lst)->label_instruc & INSTRUC))
		{
			((*lst)->i) = stock_i;
			write_upcode(tmp, (*lst)->i, lst);
			write_ocp(tmp, (*lst)->i, lst);
			ref = -1;
			while ((*lst)->p[++ref].if_no_params == 1)
				write_one_arg(tmp, ref, lst);
			stock_i = ((*lst)->i);
		}
		free((*lst)->line);
		lst = &(*lst)->next;
	}
}

int			fill_header(char **tmp, t_lst_asm **lst, t_asm *header, int fd)
{
	int i;

	i = 3;
	i = write_exe_code(tmp, i, fd);
	i = write_prog_name(tmp, fd, header->head.prog_name, PROG_NAME_LENGTH);
	i = write_null(tmp, i, fd);
	i = write_nb_arg(tmp, i, fd, lst);
	i = write_prog_name(tmp, fd, header->head.comment, COMMENT_LENGTH);
	i = write_null(tmp, i, fd);
	(*lst)->i = i;
	return (1);
}

int			write_file(char *argv, t_lst_asm **lst, t_asm *header)
{
	int		fd;
	char	*tmp;

	if ((tmp = ft_strnew(PROG_NAME_LENGTH + \
					COMMENT_LENGTH + 16 + 2 + (*lst)->nb_final)) == NULL)
		ft_exit(1, "Malloc error (write_file)\n");
	fd = create_file(argv);
	fill_header(&tmp, lst, header, fd);
	write_all_arg(&tmp, fd, lst, 0);
	free(tmp);
	return (1);
}
