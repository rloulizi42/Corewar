/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:46:40 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/14 10:47:15 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>

int		set_champ_num(char **av, int i_av, int ac, t_vm *vm)
{
	int		num;

	num = 0;
	if (i_av + 1 < ac && ft_strisdigit(av[i_av + 1]))
		num = ft_atoi(av[i_av + 1]);
	else
		ft_exit("Argument error.\n", -1);
	vm->next_num = num;
	return (0);
}

int		set_dump_param(char **av, int i_av, int ac, t_vm *vm)
{
	if (i_av + 1 < ac && ft_strisdigit(av[i_av + 1]))
		vm->dump = ft_atoi(av[i_av + 1]);
	else
		ft_exit("Argument error.\n", -1);
	return (0);
}

int		set_verb_param(char **av, int i_av, int ac, t_vm *vm)
{
	if (i_av + 1 < ac && ft_strisdigit(av[i_av + 1]))
		vm->verbose = ft_atoi(av[i_av + 1]);
	else
		ft_exit("Argument error.\n", -1);
	return (0);
}

int		set_viewer_param(char **av, int i_av, int ac, t_vm *vm)
{
	vm->viewer = 1;
	av = NULL;
	i_av = 0;
	ac = 0;
	return (0);
}
