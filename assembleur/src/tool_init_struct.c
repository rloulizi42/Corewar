/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:52:12 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/13 17:45:37 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/asm.h"

static	void	init_header(t_asm *tmp)
{
	tmp->head.magic = 0;
	tmp->back_n = 0;
	tmp->head.prog_size = 0;
	tmp->stock_name = 0;
	tmp->stock_comment = 0;
	ft_bzero(&tmp->head.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(&tmp->head.comment, COMMENT_LENGTH + 1);
}

static	void	init_asm(t_asm *tmp)
{
	tmp->fd = 0;
}

static	void	init_ref_value(t_asm *tmp)
{
	tmp->ref.name = 0;
	tmp->ref.len_string_name = 0;
}

t_asm			init_strcut_header(void)
{
	t_asm tmp;

	init_header(&tmp);
	init_asm(&tmp);
	init_ref_value(&tmp);
	return (tmp);
}
