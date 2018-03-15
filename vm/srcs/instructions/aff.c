/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:36:29 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/21 11:27:25 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <locale.h>
#include <stdint.h>

void	ft_aff(t_vm *vm, t_list_cpu *cpu)
{
	int	reg;
	int	c;

	setlocale(LC_ALL, "");
	if (cpu->ocp == 0x40)
	{
		if (vm->viewer == 0)
		{
			reg = vm->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
			if (reg < 0 || reg >= REG_NUMBER)
				return ;
			c = regtonb(cpu, reg);
			if ((vm->verbose & 0x10) == 16)
				ft_printf("Aff: %C\n", c);
			else
				ft_printf("Aff: %c\n", c);
			cpu->carry = (c == 0) ? 1 : 0;
		}
	}
}
