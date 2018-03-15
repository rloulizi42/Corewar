/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:11:25 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/20 16:31:47 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_vm *vm, t_list_cpu *cpu)
{
	int i;
	int nb;

	nb = (vm->arena[(cpu->pc + 4) % MEM_SIZE]) |
		(vm->arena[(cpu->pc + 3) % MEM_SIZE] << 8) |
		(vm->arena[(cpu->pc + 2) % MEM_SIZE] << 16) |
		(vm->arena[(cpu->pc + 1) % MEM_SIZE] << 24);
	i = -1;
	while (++i < vm->nb_champs)
	{
		if (vm->num_champs[i] == nb)
		{
			vm->live = nb;
			vm->live_by_champs[i]++;
			if (vm->viewer == 0 && (vm->verbose & 0x01) == 1)
				ft_printf("Le joueur %s ( %d ); raporter comme étant en vie\n",
						vm->data_champs[i]->prog_name, i + 1);
		}
	}
	vm->nbr_live_cycle_to_die++;
	cpu->live++;
}
