/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:58:27 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/21 12:17:29 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sti(t_vm *vm, t_list_cpu *cpu)
{
	g_sti[(unsigned char)cpu->ocp](vm, cpu);
}

void	ft_sti_rrr(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int r2;
	int r3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	r2 = vm->arena[(cpu->pc + 3) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
	if (r1 < 0 || r2 < 0 || r3 < 0 || r1 >= REG_NUMBER
			|| r2 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	r2 = regtonb(cpu, r2);
	r3 = regtonb(cpu, r3);
	r2 = (r2 + r3) % IDX_MOD;
	if ((cpu->pc + r2) < 0)
		r2 = ((unsigned short)r2) % MEM_SIZE;
	vm->arena[(cpu->pc + r2) % MEM_SIZE] = r1 >> 24;
	vm->arena[(cpu->pc + r2 + 1) % MEM_SIZE] = r1 >> 16;
	vm->arena[(cpu->pc + r2 + 2) % MEM_SIZE] = r1 >> 8;
	vm->arena[(cpu->pc + r2 + 3) % MEM_SIZE] = r1;
	report_property(vm, cpu, cpu->pc + r2, 4);
}

void	ft_sti_rdr(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int n2;
	int r3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	n2 = direct_2(vm, cpu, 2);
	r3 = vm->arena[(cpu->pc + 5) % MEM_SIZE] - 1;
	if (r1 < 0 || r3 < 0 || r1 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	r3 = regtonb(cpu, r3);
	n2 = (n2 + r3) % IDX_MOD;
	if ((cpu->pc + n2) < 0)
		n2 = ((unsigned short)n2) % MEM_SIZE;
	vm->arena[(cpu->pc + n2) % MEM_SIZE] = r1 >> 24;
	vm->arena[(cpu->pc + n2 + 1) % MEM_SIZE] = r1 >> 16;
	vm->arena[(cpu->pc + n2 + 2) % MEM_SIZE] = r1 >> 8;
	vm->arena[(cpu->pc + n2 + 3) % MEM_SIZE] = r1;
	report_property(vm, cpu, cpu->pc + n2, 4);
}

void	ft_sti_rir(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int n2;
	int r3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	n2 = indirect_var(vm, cpu, 2);
	r3 = vm->arena[(cpu->pc + 5) % MEM_SIZE] - 1;
	if (r1 < 0 || r3 < 0 || r1 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	r3 = regtonb(cpu, r3);
	n2 = (n2 + r3) % IDX_MOD;
	if ((cpu->pc + n2) < 0)
		n2 = ((unsigned short)n2) % MEM_SIZE;
	vm->arena[(cpu->pc + n2) % MEM_SIZE] = r1 >> 24;
	vm->arena[(cpu->pc + n2 + 1) % MEM_SIZE] = r1 >> 16;
	vm->arena[(cpu->pc + n2 + 2) % MEM_SIZE] = r1 >> 8;
	vm->arena[(cpu->pc + n2 + 3) % MEM_SIZE] = r1;
	report_property(vm, cpu, cpu->pc + n2, 4);
}

void	ft_sti_rrd(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int r2;
	int r3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	r2 = vm->arena[(cpu->pc + 3) % MEM_SIZE] - 1;
	r3 = direct_2(vm, cpu, 3);
	if (r1 < 0 || r2 < 0 || r1 >= REG_NUMBER || r2 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	r2 = regtonb(cpu, r2);
	r2 = (r2 + r3) % IDX_MOD;
	if ((cpu->pc + r2) < 0)
		r2 = ((unsigned short)r2) % MEM_SIZE;
	vm->arena[(cpu->pc + r2) % MEM_SIZE] = r1 >> 24;
	vm->arena[(cpu->pc + r2 + 1) % MEM_SIZE] = r1 >> 16;
	vm->arena[(cpu->pc + r2 + 2) % MEM_SIZE] = r1 >> 8;
	vm->arena[(cpu->pc + r2 + 3) % MEM_SIZE] = r1;
	report_property(vm, cpu, cpu->pc + r2, 4);
}
