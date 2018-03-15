/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:27:04 by rloulizi          #+#    #+#             */
/*   Updated: 2018/03/01 11:00:12 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sti_rdd(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int n2;
	int n3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	n2 = direct_2(vm, cpu, 2);
	n3 = direct_2(vm, cpu, 4);
	if (r1 < 0 || r1 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	n2 = (n2 + n3) % IDX_MOD;
	if ((cpu->pc + n2) < 0)
		n2 = ((unsigned short)n2) % MEM_SIZE;
	vm->arena[(cpu->pc + n2) % MEM_SIZE] = r1 >> 24;
	vm->arena[(cpu->pc + n2 + 1) % MEM_SIZE] = r1 >> 16;
	vm->arena[(cpu->pc + n2 + 2) % MEM_SIZE] = r1 >> 8;
	vm->arena[(cpu->pc + n2 + 3) % MEM_SIZE] = r1;
	report_property(vm, cpu, cpu->pc + n2, 4);
}

void	ft_sti_rid(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int n2;
	int n3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	n2 = indirect_var(vm, cpu, 2);
	n3 = direct_2(vm, cpu, 4);
	if (r1 < 0 || r1 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	n2 = (n2 + n3) % IDX_MOD;
	if ((cpu->pc + n2) < 0)
		n2 = ((unsigned short)n2) % MEM_SIZE;
	vm->arena[(cpu->pc + n2) % MEM_SIZE] = r1 >> 24;
	vm->arena[(cpu->pc + n2 + 1) % MEM_SIZE] = r1 >> 16;
	vm->arena[(cpu->pc + n2 + 2) % MEM_SIZE] = r1 >> 8;
	vm->arena[(cpu->pc + n2 + 3) % MEM_SIZE] = r1;
	report_property(vm, cpu, cpu->pc + n2, 4);
}
