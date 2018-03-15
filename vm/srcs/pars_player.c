/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:51:22 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/13 14:52:10 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>

void				init_t_header(t_vm *vm, int fd)
{
	t_header	*new_header;
	int			ret;
	char		buf[4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4 + 1];

	if (!(new_header = ft_memalloc(sizeof(t_header))))
		ft_exit("Malloc error. (add_player)", -1);
	vm->data_champs[vm->nb_champs] = new_header;
	if ((ret = read(fd, buf, 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4))
			== -1 || ret < (4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4))
		ft_exit("Error in .cor file. (header)\n", -1);
	buf[ret] = '\0';
	new_header->magic = little_to_big_endian(*(unsigned int*)buf);
	if (new_header->magic != COREWAR_EXEC_MAGIC)
		ft_exit("Error in .cor file. (magic)\n", -1);
	ft_bzero(new_header->prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(new_header->prog_name, buf + 4, PROG_NAME_LENGTH);
	new_header->prog_size = little_to_big_endian(
			*(unsigned int*)(buf + 4 + PROG_NAME_LENGTH + 4));
	if (new_header->prog_size > CHAMP_MAX_SIZE)
		ft_exit("Champ size to big !\n", -1);
	ft_bzero(new_header->comment, COMMENT_LENGTH + 1);
	ft_memcpy(new_header->comment, buf + 12 + PROG_NAME_LENGTH, COMMENT_LENGTH);
}

int					add_player(char **av, int i_av, int num, t_vm *vm)
{
	int			fd;
	int			ret;
	char		buf[CHAMP_MAX_SIZE + 1];

	if (ft_strlen(av[i_av]) <= 4)
		ft_exit("Champion name is invalid\n", -1);
	if (ft_strcmp(av[i_av] + ft_strlen(av[i_av]) - 4, ".cor"))
		ft_exit("Champions need to have .cor extension\n", -1);
	set_player_number(num, vm);
	if ((fd = open(av[i_av], O_RDONLY)) == -1)
		ft_exit("Open failed.\n", -1);
	init_t_header(vm, fd);
	if ((ret = read(fd, buf, CHAMP_MAX_SIZE + 1)) == -1)
		ft_exit("Error in .cor file. (champ)\n", -1);
	if (ret != (int)vm->data_champs[vm->nb_champs]->prog_size && ret > 0)
		ft_exit("Wrong champ size \n", -1);
	if (!(vm->inst_champs[vm->nb_champs] = ft_memalloc(ret)))
		ft_exit("Malloc error. (inst_champ)\n", -1);
	ft_memcpy(vm->inst_champs[vm->nb_champs], buf, ret);
	vm->nb_champs++;
	return (0);
}
