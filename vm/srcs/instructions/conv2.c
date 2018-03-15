/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:11:58 by rloulizi          #+#    #+#             */
/*   Updated: 2018/01/31 19:00:25 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	report_property(t_vm *vm, t_list_cpu *cpu, int index, int len)
{
	char	champs;
	int		i;

	champs = vm->property[cpu->pc];
	i = -1;
	while (++i < len)
		vm->property[(index + i) % MEM_SIZE] = champs;
}

int		regtonb(t_list_cpu *cpu, int reg)
{
	int		nb;

	nb = cpu->reg[(REG_SIZE - 1) + (REG_SIZE * reg)] |
		cpu->reg[(REG_SIZE - 2) + (REG_SIZE * reg)] << 8 |
		cpu->reg[(REG_SIZE - 3) + (REG_SIZE * reg)] << 16 |
		cpu->reg[(REG_SIZE - 4) + (REG_SIZE * reg)] << 24;
	return (nb);
}

void	nbtoreg(t_list_cpu *cpu, int reg, int nb)
{
	cpu->reg[(REG_SIZE - 1) + (REG_SIZE * reg)] = nb;
	cpu->reg[(REG_SIZE - 2) + (REG_SIZE * reg)] = nb >> 8;
	cpu->reg[(REG_SIZE - 3) + (REG_SIZE * reg)] = nb >> 16;
	cpu->reg[(REG_SIZE - 4) + (REG_SIZE * reg)] = nb >> 24;
}
