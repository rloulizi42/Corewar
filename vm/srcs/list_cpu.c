/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:31:28 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/11 17:30:15 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include <stdlib.h>

void	update_cpu_list(t_vm *vm, t_list_cpu *new, int i)
{
	int			mem_gap_players;

	mem_gap_players = MEM_SIZE / vm->nb_champs;
	if (vm->cpu_list == NULL)
	{
		new->pc = 0;
		new->next = new;
		new->prev = new;
		vm->last_cpu = new;
	}
	else
	{
		new->pc = vm->last_cpu->pc + i * mem_gap_players;
		vm->last_cpu->next = new;
		vm->cpu_list->prev = new;
		new->prev = vm->last_cpu;
		new->next = vm->cpu_list;
	}
	vm->cpu_list = new;
}

void	create_cpu(t_vm *vm, int i)
{
	t_list_cpu	*new;

	if (!(new = ft_memalloc(sizeof(t_list_cpu))))
		ft_exit("Malloc error.\n", -1);
	nbtoreg(new, 0, vm->num_champs[i]);
	new->wait = -1;
	update_cpu_list(vm, new, i);
	vm->nb_cpu++;
}

void	add_new_cpu(t_vm *vm, t_list_cpu *parent, int pc)
{
	t_list_cpu *new;

	if (!(new = ft_memalloc(sizeof(t_list_cpu))))
		ft_exit("Malloc error.\n", -1);
	new->pc = pc;
	new->wait = -1;
	new->carry = parent->carry;
	ft_memcpy(new->reg, parent->reg, REG_SIZE * REG_NUMBER);
	new->prev = vm->last_cpu;
	new->next = vm->last_cpu->next;
	vm->last_cpu->next->prev = new;
	vm->last_cpu->next = new;
	vm->cpu_list = new;
	vm->nb_cpu++;
}

void	del_cpu(t_vm *vm, t_list_cpu *cpu)
{
	if (cpu == vm->cpu_list && cpu == vm->last_cpu)
	{
		free(cpu);
		vm->cpu_list = NULL;
		vm->last_cpu = NULL;
		return ;
	}
	if (cpu == vm->last_cpu)
		vm->last_cpu = cpu->prev;
	if (cpu == vm->cpu_list)
		vm->cpu_list = cpu->next;
	cpu->prev->next = cpu->next;
	cpu->next->prev = cpu->prev;
	free(cpu);
	vm->nb_cpu--;
}
