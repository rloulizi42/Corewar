/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:50:19 by ajehanno          #+#    #+#             */
/*   Updated: 2018/02/20 16:17:30 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_ncurses_wait_no_run(t_vm *vm)
{
	int		r;

	r = getch();
	if (r == 32)
	{
		vm->run = 1;
		nodelay(vm->win, 1);
		ft_memcpy(vm->status_run, "** RUNNING **\0", 14);
		return (0);
	}
	if (r == 115)
		return (0);
	if (r == 114 && vm->speed_run >= 1000)
		vm->speed_run -= 1000;
	if (r == 113)
		vm->speed_run += 1000;
	if (r == 48)
		vm->speed_run = 0;
	return (1);
}

int		ft_ncurses_wait(t_vm *vm)
{
	if (vm->run == 1 && getch() == 32)
	{
		vm->run = 0;
		nodelay(vm->win, 0);
		ft_memcpy(vm->status_run, "** PAUSED ** \0", 14);
		move(1, 200);
		printw("%s", vm->status_run);
		refresh();
		return (0);
	}
	if (vm->run == 0)
		if ((ft_ncurses_wait_no_run(vm)) == 1)
			return (1);
	return (0);
}

void	ft_ncurses_print_cpu(t_vm *vm)
{
	t_list_cpu	*cpu;
	t_list_cpu	*first_cpu;
	int			i;
	int			y;

	y = 65;
	cpu = vm->cpu_list;
	first_cpu = NULL;
	while (cpu != first_cpu)
	{
		first_cpu = vm->cpu_list;
		i = -1;
		move(++y, 0);
		printw("CPU au PC : %d -> ", cpu->pc);
		while (++i < REG_NUMBER)
		{
			printw("| %.8x ",
					cpu->reg[(REG_SIZE - 1) + (i * REG_SIZE)] |
					cpu->reg[(REG_SIZE - 2) + (i * REG_SIZE)] << 8 |
					cpu->reg[(REG_SIZE - 3) + (i * REG_SIZE)] << 16 |
					cpu->reg[(REG_SIZE - 4) + (i * REG_SIZE)] << 24);
		}
		cpu = cpu->next;
	}
}

void	ft_ncurses_print_live(t_vm *vm)
{
	t_list_cpu	*cpu;
	int			y;
	int			c;

	y = 28;
	c = 1;
	cpu = vm->cpu_list;
	if (cpu)
	{
		move(++y, 200);
		printw("%d : CPU au PC : %d -> L %d | C : %d",
			c++, cpu->pc, cpu->live, cpu->carry);
		cpu = cpu->next;
	}
	while (cpu != vm->cpu_list)
	{
		move(++y, 200);
		printw("%d : CPU au PC : %d -> L %d | C : %d",
				c++, cpu->pc, cpu->live, cpu->carry);
		cpu = cpu->next;
	}
}
