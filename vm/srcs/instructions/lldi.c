/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:22:14 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/02 15:46:57 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lldi(t_vm *vm, t_list_cpu *cpu)
{
	g_lldi[(unsigned char)cpu->ocp](vm, cpu);
}

void	ft_lldi_rrr(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int r2;
	int r3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	r2 = vm->arena[(cpu->pc + 3) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
	if (r1 < 0 || r2 < 0 || r3 < 0 || r1 >= REG_NUMBER
			|| r2 >= REG_NUMBER || r3 >= REG_NUMBER)
	{
		return ;
	}
	r1 = regtonb(cpu, r1);
	r2 = regtonb(cpu, r2);
	r1 = r1 + r2;
	r1 = direct_4(vm, cpu, r1 - 1);
	nbtoreg(cpu, r3, r1);
	cpu->carry = (r1 == 0) ? 1 : 0;
}

void	ft_lldi_drr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int r2;
	int r3;

	n1 = direct_2(vm, cpu, 1);
	r2 = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 5) % MEM_SIZE] - 1;
	if (r2 < 0 || r3 < 0 || r2 >= REG_NUMBER || r3 >= REG_NUMBER)
	{
		return ;
	}
	r2 = regtonb(cpu, r2);
	n1 = n1 + r2;
	n1 = direct_4(vm, cpu, n1 - 1);
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}

void	ft_lldi_rdr(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int n2;
	int r3;

	r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	n2 = direct_2(vm, cpu, 2);
	r3 = vm->arena[(cpu->pc + 5)] - 1;
	if (r1 < 0 || r3 < 0 || r1 >= REG_NUMBER || r3 >= REG_NUMBER)
	{
		return ;
	}
	r1 = regtonb(cpu, r1);
	r1 = r1 + n2;
	r1 = direct_4(vm, cpu, r1 - 1);
	nbtoreg(cpu, r3, r1);
	cpu->carry = (r1 == 0) ? 1 : 0;
}

void	ft_lldi_ddr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int n2;
	int r3;

	n1 = direct_2(vm, cpu, 1);
	n2 = direct_2(vm, cpu, 3);
	r3 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	if (r3 < 0 || r3 >= REG_NUMBER)
	{
		return ;
	}
	n1 = n1 + n2;
	nbtoreg(cpu, r3, n1 - 1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}
