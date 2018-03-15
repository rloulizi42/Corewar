/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:35:51 by sflinois          #+#    #+#             */
/*   Updated: 2018/02/21 12:27:07 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_inst	g_inst[] =
{
	ft_live,
	ft_ld,
	ft_st,
	ft_add,
	ft_sub,
	ft_and,
	ft_or,
	ft_xor,
	ft_zjmp,
	ft_ldi,
	ft_sti,
	ft_fork,
	ft_lld,
	ft_lldi,
	ft_lfork,
	ft_aff,
};

void	exec_cpu_op(t_vm *vm, t_list_cpu *cpu)
{
	if (cpu->wait == -1)
	{
		if (vm->arena[cpu->pc] > 0 && vm->arena[cpu->pc] <= 16)
		{
			cpu->wait = g_op_tab[vm->arena[cpu->pc] - 1].nb_cycle - 1;
			cpu->opcode = vm->arena[cpu->pc];
			cpu->nb_param = g_op_tab[cpu->opcode - 1].nb_param;
		}
		else
		{
			cpu->wait = 0;
			cpu->opcode = 0;
			cpu->nb_param = 0;
		}
	}
	if (cpu->wait == 0)
	{
		if (cpu->opcode > 0 && cpu->opcode <= 16)
		{
			cpu->ocp = vm->arena[(cpu->pc + 1) % MEM_SIZE];
			g_inst[cpu->opcode - 1](vm, cpu);
		}
		ft_move_pc(vm, cpu);
	}
	cpu->wait--;
}

void	exec_cycle(t_vm *vm)
{
	t_list_cpu	*current_cpu;

	current_cpu = vm->cpu_list;
	if (current_cpu->pc > MEM_SIZE)
		current_cpu->pc %= MEM_SIZE;
	exec_cpu_op(vm, current_cpu);
	current_cpu = current_cpu->next;
	while (current_cpu != vm->cpu_list)
	{
		if (current_cpu->pc >= MEM_SIZE)
			current_cpu->pc %= MEM_SIZE;
		exec_cpu_op(vm, current_cpu);
		current_cpu = current_cpu->next;
	}
}
