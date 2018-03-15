/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:27:17 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/21 12:01:59 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_st_invalid(t_vm *vm, t_list_cpu *cpu, int nb)
{
	(void)vm;
	(void)cpu;
	(void)nb;
}

void	ft_st_r(t_vm *vm, t_list_cpu *cpu, int nb)
{
	int		reg;

	reg = vm->arena[(cpu->pc + 3) % MEM_SIZE] - 1;
	if (reg < 0 || reg >= REG_NUMBER)
		return ;
	cpu->reg[(REG_SIZE - 1) + (REG_SIZE * reg)] = nb;
	cpu->reg[(REG_SIZE - 2) + (REG_SIZE * reg)] = nb >> 8;
	cpu->reg[(REG_SIZE - 3) + (REG_SIZE * reg)] = nb >> 16;
	cpu->reg[(REG_SIZE - 4) + (REG_SIZE * reg)] = nb >> 24;
}

void	ft_st_i(t_vm *vm, t_list_cpu *cpu, int nb)
{
	int index;

	index = indirect(vm, cpu, 2);
	vm->arena[(cpu->pc + index) % MEM_SIZE] = nb >> 24;
	vm->arena[(cpu->pc + index + 1) % MEM_SIZE] = nb >> 16;
	vm->arena[(cpu->pc + index + 2) % MEM_SIZE] = nb >> 8;
	vm->arena[(cpu->pc + index + 3) % MEM_SIZE] = nb;
	report_property(vm, cpu, cpu->pc + index, 4);
}

void	ft_st(t_vm *vm, t_list_cpu *cpu)
{
	int		nb;
	int		reg;

	reg = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	if (reg < 0 || reg >= REG_NUMBER)
		return ;
	nb = regtonb(cpu, reg);
	g_st[(unsigned char)cpu->ocp](vm, cpu, nb);
}
