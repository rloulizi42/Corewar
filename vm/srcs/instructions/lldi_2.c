/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:48:32 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/02 15:47:08 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lldi_idr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int n2;
	int r3;

	n1 = indirect_var(vm, cpu, 1);
	n2 = direct_2(vm, cpu, 2);
	r3 = vm->arena[(cpu->pc + 6) % MEM_SIZE] - 1;
	if (r3 < 0 || r3 >= REG_NUMBER)
	{
		return ;
	}
	n1 = n1 + n2;
	n1 = direct_4(vm, cpu, n1 - 1);
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}

void	ft_lldi_irr(t_vm *vm, t_list_cpu *cpu)
{
	int n1;
	int r2;
	int r3;

	n1 = indirect_var(vm, cpu, 1);
	r2 = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
	r3 = vm->arena[(cpu->pc + 5) % MEM_SIZE] - 1;
	if (r2 < 0 || r3 < 0 || r2 >= REG_NUMBER || r3 >= REG_NUMBER)
	{
		return ;
	}
	r2 = regtonb(cpu, r2);
	n1 = n1 + r2;
	nbtoreg(cpu, r3, n1);
	cpu->carry = (n1 == 0) ? 1 : 0;
}
