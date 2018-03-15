/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:47:41 by ajehanno          #+#    #+#             */
/*   Updated: 2018/03/09 21:02:47 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_exit_usage_vm(void)
{
	char	*msg;

	msg = "usage : ./corewar  [-dump N -n N -b N | -v -b N] "\
		"[[-n number] champion1.cor] <...>\n\n"\
		"-n N\t: Number assigned to the player\n"\
		"#### TEXT OUTPUT MODE ###########################################"\
		"#################\n"\
		"All standard outputs are hidden if the viewer is enabled"\
		" (including \"aff\")\n"\
		"-dump N\t: Dumps memory after N cycles then exits\n"\
		"-b N\t: Verbosity levels, "\
		"can be added together to enable several\n"\
		"\t  - 1  : Show lives\n\t  - 2 : Show cycles\n"\
		"\t  - 4  : Show PC movements (Except for jumps)\n"\
		"\t  - 8  : Show informations of Champions\n"\
		"\t  - 16 : Use unicode for Aff\n"\
		"#### NCURSES OUTPUT MODE ########################################"\
		"#################\n"\
		"-v\t: Ncurses output mode (VIEWER)\n"\
		"-b N\t: Verbosity levels, "\
		"can be added together to enable several\n"\
		"\t  - 32 : Show CPU Content (limit 16) and"\
		" Status live and carry (limit 48)\n##############################"\
		"####################################################\n\n";
	ft_exit(msg, 0);
}

int			ft_exit_error_binarie(char *binarie)
{
	ft_printf("{red}Champ : {eoc}%s{red} is invalid !\n", binarie);
	return (-1);
}
