/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:39:19 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/11 16:58:31 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include <stdlib.h>

int		init_corewar(t_vm *vm)
{
	int			i;
	char		*tmp;

	i = 0;
	while (i < vm->nb_champs)
	{
		create_cpu(vm, i);
		ft_memcpy(vm->arena + vm->cpu_list->pc, vm->inst_champs[i]
				, vm->data_champs[i]->prog_size);
		tmp = ft_strnew(vm->data_champs[i]->prog_size);
		ft_memset(tmp, i + 1, vm->data_champs[i]->prog_size);
		ft_memcpy(vm->property + vm->cpu_list->pc, tmp,
				vm->data_champs[i]->prog_size);
		free(tmp);
		i++;
	}
	if (vm->viewer == 1)
		ft_ncurses(vm);
	vm->speed_run = 5000;
	return (0);
}

int		check_cpu_death(t_vm *vm)
{
	t_list_cpu	*current_cpu;
	t_list_cpu	*start;

	current_cpu = vm->cpu_list;
	start = NULL;
	while (current_cpu != start)
	{
		start = vm->cpu_list;
		if (current_cpu->live == 0)
		{
			if (current_cpu->next == current_cpu)
				return (-1);
			current_cpu = current_cpu->next;
			del_cpu(vm, current_cpu->prev);
		}
		else
		{
			current_cpu->live = 0;
			current_cpu = current_cpu->next;
		}
	}
	return (0);
}

int		check_cycle_to_die(t_vm *vm)
{
	if (vm->cycle_check + 1 >= vm->cycle_to_die ||
			vm->cycle_to_die < 0)
	{
		if (vm->cycle_to_die < 0 || check_cpu_death(vm))
			return (-1);
		if (vm->nbr_live_cycle_to_die >= NBR_LIVE ||
				vm->count_checks == MAX_CHECKS)
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			vm->count_checks = 1;
			vm->nbr_live_cycle_to_die = 0;
			vm->live_by_champs[0] = 0;
			vm->live_by_champs[1] = 0;
			vm->live_by_champs[2] = 0;
			vm->live_by_champs[3] = 0;
			if (vm->viewer == 0 && (vm->verbose & 0x02) == 2)
				ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		}
		else
			vm->count_checks++;
		vm->cycle_check = 0;
	}
	else
		vm->cycle_check++;
	return (0);
}

int		run_corewar(t_vm *vm)
{
	int			r;

	init_corewar(vm);
	init_tab();
	r = 0;
	while ((unsigned int)vm->cycle < (unsigned int)vm->dump && vm->cpu_list)
	{
		if (vm->viewer == 0 & (vm->verbose & 0x02) == 2)
			ft_printf("It is now cycle %d\n", vm->cycle + 1);
		if (vm->viewer == 1)
		{
			ft_ncurses_print_arena(vm, vm->cycle);
			r = ft_ncurses_wait(vm);
		}
		if (r == 0)
		{
			exec_cycle(vm);
			if (check_cycle_to_die(vm))
				return (1);
			vm->cycle++;
		}
		if (vm->viewer == 1)
			usleep(vm->speed_run);
	}
	return (0);
}
