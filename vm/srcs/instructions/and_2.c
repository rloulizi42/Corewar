/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:47:29 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/21 12:24:11 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_and_iir(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int n2;
	int r3;

	n1 = indirect_var(vm, cpu, 1);
	n2 = indirect_var(vm, cpu, 3);
	r3 = vm->arena[(cpu->pc + 6) % MEM_SIZE] - 1;
	if (r3 < 0 || r3 >= REG_NUMBER)
		return ;
	n1 = n1 & n2;
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}

void	ft_and_dir(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int n2;
	int r3;

	n1 = direct_4(vm, cpu, 1);
	n2 = indirect_var(vm, cpu, 5);
	r3 = vm->arena[(cpu->pc + 8) % MEM_SIZE] - 1;
	if (r3 < 0 || r3 >= REG_NUMBER)
		return ;
	n1 = n1 & n2;
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}

void	ft_and_rdr(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int n2;
	int r3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	n2 = direct_4(vm, cpu, 2);
	r3 = vm->arena[(cpu->pc + 7) % MEM_SIZE] - 1;
	if (r1 < 0 || r3 < 0 || r1 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	n2 = r1 & n2;
	nbtoreg(cpu, r3, r1);
	cpu->carry = (n2 == 0) ? 1 : 0;
}

void	ft_and_idr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int n2;
	int r3;

	n1 = indirect_var(vm, cpu, 1);
	n2 = direct_4(vm, cpu, 3);
	r3 = vm->arena[(cpu->pc + 8) % MEM_SIZE] - 1;
	if (r3 < 0 || r3 >= REG_NUMBER)
		return ;
	n2 = n1 & n2;
	nbtoreg(cpu, r3, n2);
	cpu->carry = (n2 == 0) ? 1 : 0;
}

void	ft_and_ddr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int n2;
	int r3;

	n1 = direct_4(vm, cpu, 1);
	n2 = direct_4(vm, cpu, 5);
	r3 = vm->arena[(cpu->pc + 10) % MEM_SIZE] - 1;
	if (r3 < 0 || r3 >= REG_NUMBER)
		return ;
	n1 = n1 & n2;
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}
