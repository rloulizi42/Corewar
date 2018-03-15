/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:44:35 by ajehanno          #+#    #+#             */
/*   Updated: 2018/02/21 10:50:25 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_move_dir_4(t_vm *vm, t_list_cpu *data)
{
	int		drop;

	(void)vm;
	drop = 2;
	if ((data->ocp & 0xC0) == 0x40 && data->nb_param > 0)
		drop += 1;
	if ((data->ocp << 2 & 0xC0) == 0x40 && data->nb_param > 1)
		drop += 1;
	if ((data->ocp << 4 & 0xC0) == 0x40 && data->nb_param > 2)
		drop += 1;
	if ((data->ocp & 0xC0) == 0xC0 && data->nb_param > 0)
		drop += 2;
	if ((data->ocp << 2 & 0xC0) == 0xC0 && data->nb_param > 1)
		drop += 2;
	if ((data->ocp << 4 & 0xC0) == 0xC0 && data->nb_param > 2)
		drop += 2;
	if ((data->ocp & 0xC0) == 0x80 && data->nb_param > 0)
		drop += 4;
	if ((data->ocp << 2 & 0xC0) == 0x80 && data->nb_param > 1)
		drop += 4;
	if ((data->ocp << 4 & 0xC0) == 0x80 && data->nb_param > 2)
		drop += 4;
	ft_show_move_pc(vm, data, drop);
	data->pc += drop;
}

void		ft_move_dir_2(t_vm *vm, t_list_cpu *data)
{
	int		drop;

	(void)vm;
	drop = 2;
	if ((data->ocp & 0xC0) == 0x40 && data->nb_param > 0)
		drop += 1;
	if ((data->ocp << 2 & 0xC0) == 0x40 && data->nb_param > 1)
		drop += 1;
	if ((data->ocp << 4 & 0xC0) == 0x40 && data->nb_param > 2)
		drop += 1;
	if ((data->ocp & 0xC0) == 0xC0 && data->nb_param > 0)
		drop += 2;
	if ((data->ocp << 2 & 0xC0) == 0xC0 && data->nb_param > 1)
		drop += 2;
	if ((data->ocp << 4 & 0xC0) == 0xC0 && data->nb_param > 2)
		drop += 2;
	if ((data->ocp & 0xC0) == 0x80 && data->nb_param > 0)
		drop += 2;
	if ((data->ocp << 2 & 0xC0) == 0x80 && data->nb_param > 1)
		drop += 2;
	if ((data->ocp << 4 & 0xC0) == 0x80 && data->nb_param > 2)
		drop += 2;
	ft_show_move_pc(vm, data, drop);
	data->pc += drop;
}

static void	ft_move_zjmp(t_vm *vm, t_list_cpu *data)
{
	int index;

	index = indirect(vm, data, 0);
	if (data->carry == 1)
		data->pc += index;
	else
		data->pc += 3;
}

void		ft_move_pc(t_vm *vm, t_list_cpu *data)
{
	(void)vm;
	if (data->opcode < 1 || data->opcode > 16)
		data->pc++;
	else if (data->opcode != 1 && data->opcode != 9 &&
			data->opcode != 12 && data->opcode != 15 &&
			data->opcode != 0 && g_op_tab[data->opcode - 1].size_dir == 0)
		ft_move_dir_4(vm, data);
	else if (data->opcode != 1 && data->opcode != 9 &&
			data->opcode != 12 && data->opcode != 15 &&
			data->opcode != 0 && g_op_tab[data->opcode - 1].size_dir == 1)
		ft_move_dir_2(vm, data);
	else if (data->opcode == 1)
	{
		ft_show_move_pc(vm, data, 5);
		data->pc += 5;
	}
	else if (data->opcode == 12 || data->opcode == 15)
	{
		ft_show_move_pc(vm, data, 3);
		data->pc += 3;
	}
	else if (data->opcode == 9)
		ft_move_zjmp(vm, data);
	data->pc = (data->pc >= MEM_SIZE) ? data->pc % MEM_SIZE : data->pc;
}
