/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:03:18 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/16 16:21:39 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_add(t_vm *vm, t_list_cpu *cpu)
{
	int r1;
	int r2;
	int r3;
	int nb;

	if (cpu->ocp == 0x54)
	{
		r1 = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
		r2 = vm->arena[(cpu->pc + 3) % MEM_SIZE] - 1;
		r3 = vm->arena[(cpu->pc + 4) % MEM_SIZE] - 1;
		if (r1 < 0 || r2 < 0 || r3 < 0 || r1 >= REG_NUMBER ||
				r2 >= REG_NUMBER || r3 >= REG_NUMBER)
			return ;
		r1 = regtonb(cpu, r1);
		r2 = regtonb(cpu, r2);
		nb = r1 + r2;
		nbtoreg(cpu, r3, nb);
		cpu->carry = (nb == 0) ? 1 : 0;
	}
}
