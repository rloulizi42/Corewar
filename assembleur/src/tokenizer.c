/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:54:37 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/14 15:08:46 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	pars le param a partir de i, return la postion du prochain params si ok
**	sinon return (-1) si rien est trouve et erreur dans le fichier
*/

int			parsing_params(int i, char *line, t_lst_asm **lst, int ref)
{
	static	const t_param	params_list[] = {
		{REG, f_reg, 1},
		{DIR_LABEL, f_label_dir, 2},
		{DIR_NB, f_nb_dir, 1},
		{IND_LABEL, f_label_indir, 1},
		{IND_NB, f_nb_indir, 12},
		{0, 0, 0},
	};
	int						pos;
	int						max;

	pos = -1;
	max = ft_strlen(line);
	i = check_and_fill_arg(line, i);
	while (i < max && params_list[++pos].params)
	{
		if (i < max && ft_strnncmp(line + i, params_list[pos].params, \
					params_list[pos].nb_param_to_check) == 1)
		{
			if ((i = params_list[pos].f(i, line, lst, ref)) == -1)
				ft_exit(1, "Params syntax error\n");
			return (i);
		}
	}
	return (-1);
}

int			check_params(int i, char *line, t_lst_asm **lst)
{
	int nb;
	int ref;

	ref = 0;
	nb = g_op_tab[(*lst)->tab].nb_param;
	init_struct_params(nb, lst);
	check_diez(line, i);
	while (ref < nb)
	{
		if ((i = parsing_params(i, line, lst, ref)) == -1)
			ft_exit(1, "Params syntax error\n");
		ref++;
		if (line[i] && line[i] == '\0' && nb > 0)
			ft_exit(1, "Not enougth params for opcode\n");
	}
	if ((*lst)->no_ocp == 1)
		(((*lst)->nb) += 1);
	else
		(((*lst)->nb) += 2);
	check_if_more_arg(line, i);
	return (1);
}

/*
**	verifie si commence par label ou non, l'upcode et ensuite les parametres
*/

int			join_before_acually(char **line, char *label, t_lst_asm **lst)
{
	char	*tmp;
	char	*stock;

	stock = *line;
	tmp = ft_strnew(ft_strlen(*line) + ft_strlen(label) + 1);
	ft_strcat(tmp, label);
	ft_strcat(tmp, *line);
	*(*(&line)) = *(&tmp);
	(*lst)->line = *(&tmp);
	free(stock);
	free(label);
	return (0);
}

int			create_token(char *line, t_lst_asm **lst)
{
	int			i;
	static char	*label = "";
	static int	if_only_label = 0;

	i = 0;
	(*lst)->nb = 0;
	if (if_only_label == 1)
		if_only_label = join_before_acually(&line, label, lst);
	if ((i = is_begin_by_label(line, lst)) == -1)
		ft_exit(1, "Label syntax error\n");
	if (!((*lst)->label_instruc & ONLY_LABEL))
	{
		if ((i = what_upcode_is(i, line, lst)) == -1)
			ft_exit(1, "Wrong upcode\n");
		if (check_params(i, line, lst) == -1)
			ft_exit(1, "Wrong param\n");
	}
	else
	{
		label = ft_strdup((*lst)->line);
		if_only_label = 1;
		(*lst)->label_instruc |= ONLY_LABEL;
	}
	return (1);
}

/*
**	parcours la liste et applique pour chaque maillion la fonction qui va
**	parser les parametres
*/

int			tokenizer(t_lst_asm **lst)
{
	int			ref;
	t_lst_asm	*tmp;
	t_lst_asm	*search;

	search = NULL;
	ref = 0;
	tmp = *lst;
	while ((*lst))
	{
		(*lst)->label_instruc = 0;
		if (create_token((*lst)->line, lst) == -1)
			ft_exit(1, "Syntax error\n");
		if ((*lst)->next)
			lst = &(*lst)->next;
		else
			break ;
	}
	lst = &tmp;
	put_pos_label_index(lst, tmp);
	search = tmp;
	lst = &tmp;
	p_label(0, lst, search, tmp);
	search = tmp;
	lst = &tmp;
	return (1);
}
