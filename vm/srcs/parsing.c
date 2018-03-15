/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:44:41 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/14 10:44:31 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>

unsigned int		little_to_big_endian(unsigned int i)
{
	return ((i >> 24) | ((i >> 8) & 0xff00) |
			((i << 8) & 0xff0000) | (i << 24));
}

void				set_mask(t_vm *vm, char *num_mask, int num, int i)
{
	*num_mask |= vm->num_champs[i] == -1 ? 0x1 : 0;
	*num_mask |= vm->num_champs[i] == -2 ? 0x2 : 0;
	*num_mask |= vm->num_champs[i] == -3 ? 0x4 : 0;
	*num_mask |= vm->num_champs[i] == -4 ? 0x8 : 0;
	if (num != 0 && vm->num_champs[i] == num)
		ft_exit("Two players have the same number !\n", -1);
}

int					set_player_number(int num, t_vm *vm)
{
	int			i;
	char		num_mask;

	if (vm->nb_champs == 4)
		ft_exit("Too much players !\n", -1);
	i = -1;
	num_mask = 0;
	while (++i < vm->nb_champs)
		set_mask(vm, &num_mask, num, i);
	i = -1;
	num_mask = ~num_mask;
	while (!(num_mask & 0x1))
	{
		num_mask = num_mask >> 1;
		i--;
	}
	if (num == 0)
		vm->num_champs[vm->nb_champs] = i;
	else
		vm->num_champs[vm->nb_champs] = num;
	vm->next_num = 0;
	return (0);
}

t_params			get_param(int i)
{
	static const t_params	param_tab[] = {
							{"-n", &set_champ_num, 1},
							{"-dump", &set_dump_param, 1},
							{"-b", &set_verb_param, 1},
							{"-v", &set_viewer_param, 0},
							{NULL, NULL, 0},
	};

	return (param_tab[i]);
}

int					pars_args(int argc, char **argv, t_vm *vm)
{
	int						i_arg;
	int						i_param;

	i_arg = 1;
	while (i_arg < argc)
	{
		i_param = 0;
		while (get_param(i_param).pars &&
				ft_strcmp(get_param(i_param).pars, argv[i_arg]))
			i_param++;
		if (get_param(i_param).pars)
		{
			get_param(i_param).fct_pars(argv, i_arg, argc, vm);
			i_arg += get_param(i_param).nb_param;
		}
		else
			add_player(argv, i_arg, vm->next_num, vm);
		i_arg++;
	}
	if (vm->nb_champs == 0)
		ft_exit_usage_vm();
	return (0);
}
