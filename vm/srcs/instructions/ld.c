/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:17:59 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/21 11:39:13 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_ld(t_vm *vm, t_list_cpu *cpu)
{
	g_ld[(unsigned char)cpu->ocp](vm, cpu);
}

void	ft_ld_dr(t_vm *vm, t_list_cpu *cpu)
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

void	ft_ld_ir(t_vm *vm, t_list_cpu *cpu)
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
