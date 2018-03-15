/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:47:08 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/11 17:59:56 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>
#include <stdlib.h>

void	init_vm(t_vm *vm)
{
	ft_bzero(vm, sizeof(t_vm));
	vm->dump = -1;
	vm->cycle_to_die = CYCLE_TO_DIE;
}

void	free_vm(t_vm *vm)
{
	t_list_cpu	*tmp;

	if (vm->cpu_list == NULL)
		return ;
	vm->cpu_list->prev->next = NULL;
	while (vm->cpu_list)
	{
		tmp = vm->cpu_list;
		vm->cpu_list = vm->cpu_list->next;
		free(tmp);
	}
}

void	ft_finish_viewer(t_vm *vm)
{
	nodelay(vm->win, 0);
	ft_memcpy(vm->status_run, "Game Finish !\0", 17);
	ft_ncurses_print_arena(vm, 0);
	getch();
	endwin();
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	init_vm(&vm);
	pars_args(argc, argv, &vm);
	ft_printf("Introducing contestants...\n");
	if ((vm.verbose & 0x08) == 8)
		ft_print_champs(&vm);
	display_contestants(&vm);
	if (run_corewar(&vm))
		display_winner(&vm);
	else if (!vm.viewer)
		ft_put_arena(&vm);
	if (vm.viewer == 1)
		ft_finish_viewer(&vm);
	free_vm(&vm);
	return (0);
}
