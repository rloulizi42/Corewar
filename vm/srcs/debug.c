/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:35:32 by ajehanno          #+#    #+#             */
/*   Updated: 2018/03/10 12:22:43 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_print_data_champs(t_vm *vm, int index_champ)
{
	ft_printf("\033[1;32mmagic\t\t: %x\n\033[1;34mname\t\t: %s\n"\
			"\033[1;36mprog_size\t: %x\n\033[1;35mcomment\t\t: %s\033[0m\n",
			vm->data_champs[index_champ]->magic,
			vm->data_champs[index_champ]->prog_name,
			vm->data_champs[index_champ]->prog_size,
			vm->data_champs[index_champ]->comment);
}

void				ft_print_inst_champs(t_vm *vm, int index_champ)
{
	unsigned int	j;

	j = 0;
	ft_printf("\033[1;33mprog\t\t:\033[0m\n");
	while (j < vm->data_champs[index_champ]->prog_size)
	{
		ft_printf("%.2hhx%.2hhx ", vm->inst_champs[index_champ][j],
				vm->inst_champs[index_champ][j + 1]);
		j += 2;
	}
	ft_printf("\n");
}

void				ft_print_champs(t_vm *vm)
{
	int				i;

	i = -1;
	while (++i < vm->nb_champs)
	{
		ft_print_data_champs(vm, i);
		ft_print_inst_champs(vm, i);
		ft_printf("\n");
	}
}

void				ft_put_arena(t_vm *vm)
{
	int				i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if ((i % 32) == 0 && i != 0)
			ft_printf("\n0x%.4x : ", i);
		if ((i % 32) == 0 && i == 0)
			ft_printf("0x0000 : ");
		ft_printf("%.2hhx ", vm->arena[i]);
	}
	ft_printf("\n");
}

void				ft_show_move_pc(t_vm *vm, t_list_cpu *cpu, int drop)
{
	int				i;

	if (vm->viewer == 0 && (vm->verbose & 0x04) == 4)
	{
		i = -1;
		if (cpu->pc == 0)
			ft_printf("ADV %d (0x0000 -> 0x%.4x) ", drop, cpu->pc + drop);
		else
			ft_printf("ADV %d (0x%.4x -> 0x%.4x) ",
					drop, cpu->pc, cpu->pc + drop);
		while (++i < drop)
			ft_printf("%.2hhx ", vm->arena[(cpu->pc + i) % MEM_SIZE]);
		ft_printf("\n");
	}
}
