/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:11:28 by rloulizi          #+#    #+#             */
/*   Updated: 2018/01/23 17:11:37 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		direct_4(t_vm *vm, t_list_cpu *cpu, int i)
{
	int		nb;

	nb = (vm->arena[(cpu->pc + i + 1) % MEM_SIZE] << 24) |
		(vm->arena[(cpu->pc + i + 2) % MEM_SIZE] << 16) |
		(vm->arena[(cpu->pc + i + 3) % MEM_SIZE] << 8) |
		(vm->arena[(cpu->pc + i + 4) % MEM_SIZE]);
	return (nb);
}

int		direct_2(t_vm *vm, t_list_cpu *cpu, int i)
{
	short		nb;

	nb = (vm->arena[(cpu->pc + i + 2) % MEM_SIZE]) |
		(vm->arena[(cpu->pc + i + 1) % MEM_SIZE] << 8);
	return (nb);
}

int		indirect_var(t_vm *vm, t_list_cpu *cpu, int i)
{
	short	index;
	int		nb;

	index = (vm->arena[(cpu->pc + i + 2) % MEM_SIZE]) |
			(vm->arena[(cpu->pc + i + 1) % MEM_SIZE] << 8);
	if (cpu->opcode < 13)
		index %= IDX_MOD;
	if ((cpu->pc + index) < 0)
		index = ((unsigned short)index) % MEM_SIZE;
	nb = (vm->arena[(cpu->pc + index) % MEM_SIZE] << 24) |
		(vm->arena[(cpu->pc + (index + 1)) % MEM_SIZE] << 16) |
		(vm->arena[(cpu->pc + (index + 2)) % MEM_SIZE] << 8) |
		(vm->arena[(cpu->pc + (index + 3)) % MEM_SIZE]);
	return (nb);
}

int		indirect(t_vm *vm, t_list_cpu *cpu, int i)
{
	short	index;

	index = (vm->arena[(cpu->pc + i + 2) % MEM_SIZE]) |
			(vm->arena[(cpu->pc + i + 1) % MEM_SIZE] << 8);
	if (cpu->opcode < 13)
		index %= IDX_MOD;
	if ((cpu->pc + index) < 0)
		index = ((unsigned short)index) % MEM_SIZE;
	return (index);
}
