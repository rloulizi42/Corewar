/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:31:48 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/13 18:13:07 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_print_cpu(t_list_cpu *cpu)
{
	int				i;

	ft_printf("PRINT_CPU----------------\n");
	i = 0;
	ft_printf("adresse : %p\n", cpu);
	ft_printf("reg : ");
	while (i < REG_SIZE * REG_NUMBER)
	{
		ft_printf("{%i}", cpu->reg[i]);
		i += REG_SIZE;
	}
	ft_printf("\npc : %i\nlive : %i\ncarry: %i\nwait: %i\nopcode: %i\n"\
			"nb_param : %i\nocp : %#x\nnext : %p\nprev : %p\n",
			cpu->pc, cpu->live, cpu->carry, cpu->wait, cpu->opcode,
			cpu->nb_param, cpu->ocp, cpu->next, cpu->prev);
}

void				ft_print_cpulist(t_vm *vm)
{
	t_list_cpu		*cpu;

	ft_printf("--PRINT_CPULIST--\n\n");
	cpu = vm->cpu_list;
	ft_print_cpu(cpu);
	cpu = cpu->next;
	while (cpu != vm->cpu_list)
	{
		ft_print_cpu(cpu);
		cpu = cpu->next;
	}
	ft_printf("-----------------\n");
}

void				display_contestants(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < vm->nb_champs)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
			i + 1, vm->data_champs[i]->prog_size,
			vm->data_champs[i]->prog_name, vm->data_champs[i]->comment);
		i++;
	}
}

void				display_winner(t_vm *vm)
{
	int	i;

	i = -1;
	while (++i < vm->nb_champs)
		if (vm->num_champs[i] == vm->live)
			break ;
	if (i != vm->nb_champs)
		ft_printf("Contestant %d, \"%s\", has won !\n",
				i + 1, vm->data_champs[i]->prog_name);
	else
		ft_printf("No constestants declared live !\n");
}
