/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:30:57 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/14 15:21:23 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		free_list(t_lst_asm **lst)
{
	t_lst_asm *tmp;

	tmp = *lst;
	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
}

int			check_first_char(char *gnl)
{
	int i;

	i = 0;
	if (gnl)
	{
		while (is_space_tab(gnl[i]))
			i++;
		if (!(gnl[i]))
			return (0);
		if (gnl[i] == '\n')
			return (0);
		else if (gnl[i] == '#' || gnl[i] == '/')
			return (0);
		else if (!(if_is_label_chars(gnl[i]) == 1))
			ft_exit(1, "Line not well formated\n");
		return (1);
	}
	return (0);
}

int			get_fd_and_line(char *line, t_asm *tmp, t_lst_asm **list)
{
	int			fd;
	char		*gnl;

	fd = 0;
	gnl = NULL;
	if ((fd = check_open_file(line)) < 0)
		ft_exit(1, "Can't open file or file does not exist\n");
	while ((get_next_line(fd, &gnl)) > 0)
	{
		if (!(tmp->ref.name & NAME_COMMENT_END))
			parsing_name_comment(gnl, tmp);
		else if ((tmp->ref.name & NAME_COMMENT_END))
		{
			if ((ft_strlen(gnl)) > 1 && check_first_char(gnl) == 1)
				create_list_asm(gnl, list);
			if (ft_strlen(gnl) == 1 && gnl[0] != '#'
					&& gnl[0] != ' ' && gnl[0] != '\t')
				ft_exit(1, "Syntax error ici\n");
		}
		free(gnl);
	}
	if (!(tmp->ref.name & NAME_COMMENT_END))
		ft_exit(1, "No name or comment found\n");
	close(fd);
	return (1);
}

int			lot_of_files(char *argv)
{
	t_asm		tmp;
	t_lst_asm	*list;

	list = NULL;
	tmp = init_strcut_header();
	if (get_fd_and_line(argv, &tmp, &list) > 0)
	{
		if (!list)
			ft_exit(1, "Instructions not found\n");
		if (tokenizer(&list) == -1)
			return (-1);
		if (analysis(&list) == -1)
			return (-1);
		if (write_file(argv, &list, &tmp) == -1)
			return (-1);
		free_list(&list);
	}
	else
	{
		ft_exit(1, "Syntax error\n");
		return (-1);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 2)
		ft_exit(1, "asm does not handle multiple files\n");
	if (argc <= 1)
		ft_putstr("./asm [file]\n");
	else
	{
		while (i < argc)
		{
			if (argv[i] != NULL)
			{
				if ((lot_of_files(argv[i])) < 0)
					ft_exit(1, "Syntax error\n");
				ft_putstr("writing ");
				ft_putendl(argv[i]);
			}
			i++;
		}
	}
	return (1);
}
