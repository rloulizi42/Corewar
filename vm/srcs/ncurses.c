/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:53:20 by ajehanno          #+#    #+#             */
/*   Updated: 2018/02/20 16:12:59 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_ncurses_init_cpu(t_vm *vm, int i)
{
	t_list_cpu	*cpu;

	cpu = vm->cpu_list;
	if (cpu->pc == i)
		attron(A_STANDOUT);
	cpu = cpu->next;
	while (cpu != vm->cpu_list)
	{
		if (cpu->pc == i)
			attron(A_STANDOUT);
		cpu = cpu->next;
	}
}

void	ft_ncurses_print_info_2(t_vm *vm, int y)
{
	move(++y, 200);
	printw("CYCLE_TO_DIE : %d", vm->cycle_to_die);
	move(++y, 200);
	printw("Cycle before Die : %d", vm->cycle_to_die - vm->cycle_check);
	move(++y, 200);
	printw("Nb_live : %d", vm->nbr_live_cycle_to_die);
	move(++y, 200);
	printw("Nb_CPU : %d", vm->nb_cpu);
	if ((vm->verbose & 0x20) == 32)
	{
		if (vm->nb_cpu < 18)
			ft_ncurses_print_cpu(vm);
		if (vm->nb_cpu < 36)
			ft_ncurses_print_live(vm);
	}
}

void	ft_ncurses_print_info(t_vm *vm, int c)
{
	int			y;
	int			i;

	y = 6;
	i = -1;
	move(1, 200);
	printw("%s", vm->status_run);
	move(3, 200);
	printw("Cycle : %d", c);
	move(4, 200);
	printw("Usleep : %d", vm->speed_run);
	while (++i < vm->nb_champs)
	{
		move(++y, 200);
		printw("Playeur %d : %s", vm->num_champs[i],
				vm->data_champs[i]->prog_name);
		move(++y, 200);
		printw("Lives in current periode : %d", vm->live_by_champs[i]);
		y += 2;
	}
	ft_ncurses_print_info_2(vm, y);
}

void	ft_ncurses_print_arena(t_vm *vm, int c)
{
	int		i;
	int		y;

	erase();
	i = -1;
	y = 0;
	while (++i < MEM_SIZE)
	{
		if ((i % 64) == 0)
			move(++y, 0);
		if (vm->property[i] != 0)
			attron(COLOR_PAIR(vm->property[i]));
		else
			attron(COLOR_PAIR(5));
		ft_ncurses_init_cpu(vm, i);
		printw("%.2hhx", vm->arena[i]);
		attroff(COLOR_PAIR(vm->property[i]));
		attroff(A_STANDOUT);
		printw(" ");
	}
	ft_ncurses_print_info(vm, c);
	refresh();
}

void	ft_ncurses(t_vm *vm)
{
	(void)vm;
	vm->win = initscr();
	noecho();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_color(COLOR_YELLOW, 400, 400, 400);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
}
