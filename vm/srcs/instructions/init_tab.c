/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:26:17 by rloulizi          #+#    #+#             */
/*   Updated: 2018/02/16 16:28:15 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_tab_ld_st_and_or(void)
{
	g_ld[0xD0] = ft_ld_ir;
	g_ld[0x90] = ft_ld_dr;
	g_st[0x50] = ft_st_r;
	g_st[0x70] = ft_st_i;
	g_and[0x54] = ft_and_rrr;
	g_and[0xD4] = ft_and_irr;
	g_and[0x94] = ft_and_drr;
	g_and[0x74] = ft_and_rir;
	g_and[0xF4] = ft_and_iir;
	g_and[0xB4] = ft_and_dir;
	g_and[0x64] = ft_and_rdr;
	g_and[0xE4] = ft_and_idr;
	g_and[0xA4] = ft_and_ddr;
	g_or[0x54] = ft_or_rrr;
	g_or[0xD4] = ft_or_irr;
	g_or[0x94] = ft_or_drr;
	g_or[0x74] = ft_or_rir;
	g_or[0xF4] = ft_or_iir;
	g_or[0xB4] = ft_or_dir;
	g_or[0x64] = ft_or_rdr;
	g_or[0xE4] = ft_or_idr;
	g_or[0xA4] = ft_or_ddr;
}

static void	init_long(void)
{
	g_lld[0xD0] = ft_lld_ir;
	g_lld[0x90] = ft_lld_dr;
	g_lldi[0x54] = ft_lldi_rrr;
	g_lldi[0xD4] = ft_lldi_irr;
	g_lldi[0x94] = ft_lldi_drr;
	g_lldi[0x64] = ft_lldi_rdr;
	g_lldi[0xE4] = ft_lldi_idr;
	g_lldi[0xA4] = ft_lldi_ddr;
}

static void	init_tab_xor_ldi_sti(void)
{
	g_xor[0x54] = ft_xor_rrr;
	g_xor[0xD4] = ft_xor_irr;
	g_xor[0x94] = ft_xor_drr;
	g_xor[0x74] = ft_xor_rir;
	g_xor[0xF4] = ft_xor_iir;
	g_xor[0xB4] = ft_xor_dir;
	g_xor[0x64] = ft_xor_rdr;
	g_xor[0xE4] = ft_xor_idr;
	g_xor[0xA4] = ft_xor_ddr;
	g_ldi[0x54] = ft_ldi_rrr;
	g_ldi[0xD4] = ft_ldi_irr;
	g_ldi[0x94] = ft_ldi_drr;
	g_ldi[0x64] = ft_ldi_rdr;
	g_ldi[0xE4] = ft_ldi_idr;
	g_ldi[0xA4] = ft_ldi_ddr;
	g_sti[0x54] = ft_sti_rrr;
	g_sti[0x64] = ft_sti_rdr;
	g_sti[0x74] = ft_sti_rir;
	g_sti[0x58] = ft_sti_rrd;
	g_sti[0x68] = ft_sti_rdd;
	g_sti[0x78] = ft_sti_rid;
}

static void	invalid(t_vm *vm, t_list_cpu *cpu)
{
	(void)vm;
	(void)cpu;
}

void		init_tab(void)
{
	int i;

	i = -1;
	while (++i < 256)
	{
		g_ld[i] = invalid;
		g_lld[i] = invalid;
		g_st[i] = ft_st_invalid;
		g_and[i] = invalid;
		g_or[i] = invalid;
		g_xor[i] = invalid;
		g_ldi[i] = invalid;
		g_lldi[i] = invalid;
		g_sti[i] = invalid;
	}
	init_tab_ld_st_and_or();
	init_long();
	init_tab_xor_ldi_sti();
}
