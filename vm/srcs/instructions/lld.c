/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:56:40 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/21 12:24:24 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lld(t_vm *vm, t_list_cpu *cpu)
{
	g_lld[(unsigned char)cpu->ocp](vm, cpu);
}

void	ft_lld_dr(t_vm *vm, t_list_cpu *cpu)
{
	int nb;
	int reg;

	nb = direct_4(vm, cpu, 1);
	reg = vm->arena[(cpu->pc + 6) % MEM_SIZE] - 1;
	if (reg < 0 || reg >= REG_NUMBER)
		return ;
	nbtoreg(cpu, reg, nb);
	cpu->carry = (nb == 0) ? 1 : 0;
}

void	ft_lld_ir(t_vm *vm, t_list_cpu *cpu)
{
	int nb;
	int reg;

	nb = indirect_var(vm, cpu, 1);
	reg = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
	if (reg < 0 || reg >= REG_NUMBER)
		return ;
	nbtoreg(cpu, reg, nb);
	cpu->carry = (nb == 0) ? 1 : 0;
}
