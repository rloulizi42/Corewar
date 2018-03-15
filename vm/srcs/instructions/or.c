/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:22:40 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/16 17:33:25 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_or(t_vm *vm, t_list_cpu *cpu)
{
	g_or[(unsigned char)cpu->ocp](vm, cpu);
}

void	ft_or_rrr(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int r2;
	int r3;
	int nb;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	r2 = vm->arena[(cpu->pc + 3) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
	if (r1 < 0 || r2 < 0 || r3 < 0 || r1 >= REG_NUMBER
			|| r2 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, r1);
	r2 = regtonb(cpu, r2);
	nb = r1 | r2;
	nbtoreg(cpu, r3, nb);
	cpu->carry = (nb == 0) ? 1 : 0;
}

void	ft_or_irr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int r2;
	int r3;

	n1 = indirect_var(vm, cpu, 1);
	r2 = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 5) % MEM_SIZE] - 1;
	if (r2 < 0 || r3 < 0 || r2 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r2 = regtonb(cpu, r2);
	n1 = n1 | r2;
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}

void	ft_or_drr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int r2;
	int r3;

	n1 = direct_4(vm, cpu, 1);
	r2 = vm->arena[(cpu->pc + 6) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 7) % MEM_SIZE] - 1;
	if (r2 < 0 || r3 < 0 || r2 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r2 = regtonb(cpu, r2);
	n1 = n1 | r2;
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}

void	ft_or_rir(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int n2;
	int r3;

	n2 = indirect_var(vm, cpu, 2);
	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 5) % MEM_SIZE] - 1;
	if (r1 < 0 || r3 < 0 || r1 >= REG_NUMBER || r3 >= REG_NUMBER)
		return ;
	r1 = regtonb(cpu, n2);
	n2 = r1 | n2;
	nbtoreg(cpu, r3, n2);
	cpu->carry = (n2 == 0) ? 1 : 0;
}
